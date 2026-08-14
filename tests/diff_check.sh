#!/usr/bin/env bash
# Differential check: runs every test against the current solution and against
# the same solution at a baseline git revision, then compares the printed
# results. Any difference means a refactor changed observable behaviour.
#
# Usage: ./diff_check.sh [baseline-revision]   (default: origin/HEAD)

set -uo pipefail

cd "$(dirname "$0")"

BASELINE="${1:-origin/HEAD}"
REPO_ROOT="$(git rev-parse --show-toplevel)"
WORKDIR="$(mktemp -d)"
STATUS=0

trap 'rm -rf "$WORKDIR"' EXIT

for test_file in *.test.cpp; do
    solution=$(sed -n 's|^#define SOLUTION_PATH "\(.*\)"$|\1|p' "$test_file")

    if [ -z "$solution" ]; then
        continue
    fi

    repo_path="${solution#../}"

    mkdir -p "$WORKDIR/$(dirname "$repo_path")"

    if ! git -C "$REPO_ROOT" show "$BASELINE:$repo_path" > "$WORKDIR/$repo_path" 2>/dev/null; then
        echo "SKIP $test_file (no baseline for $repo_path)"
        continue
    fi

    g++ -std=c++17 -O2 -o "$WORKDIR/current" "$test_file" || { STATUS=1; continue; }
    g++ -std=c++17 -O2 -DSOLUTION_PATH="\"$WORKDIR/$repo_path\"" -o "$WORKDIR/baseline" \
        "$test_file" || { STATUS=1; continue; }

    if diff <("$WORKDIR/baseline") <("$WORKDIR/current") > "$WORKDIR/diff"; then
        echo "SAME $test_file"
    else
        echo "DIFF $test_file"
        cat "$WORKDIR/diff"
        STATUS=1
    fi
done

exit "$STATUS"
