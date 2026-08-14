#!/usr/bin/env python3
"""Summarise gcov output for the solution files, ignoring the test code itself.

Run via `make coverage`, which compiles the suite with --coverage, executes it
and then feeds the generated .gcov files to this script.
"""
import re
import sys
from pathlib import Path

LINE = re.compile(r"^\s*(-|#####|=====|[0-9]+\*?):\s*\d+:")


def solution_files(gcov_dir: Path) -> dict[str, tuple[int, int]]:
    """Maps solution path -> (covered lines, instrumented lines)."""
    results: dict[str, tuple[int, int]] = {}
    for gcov_file in sorted(gcov_dir.glob("*.gcov")):
        source = None
        covered = 0
        total = 0
        for line in gcov_file.read_text(errors="replace").splitlines():
            if line.startswith("        -:    0:Source:"):
                source = line.split("Source:", 1)[1]
                continue
            if not LINE.match(line):
                continue
            count = line.split(":", 1)[0].strip()
            if count == "-":
                continue
            total += 1
            if count not in ("#####", "====="):
                covered += 1
        if source is None or "/tests/" in source or source.endswith((".h", "main.cpp")):
            continue
        name = source.split("/")[-2] if "/" in source else source
        previous = results.get(name, (0, 0))
        results[name] = (max(previous[0], covered), max(previous[1], total))
    return results


def main() -> int:
    gcov_dir = Path(sys.argv[1] if len(sys.argv) > 1 else "build/gcov")
    if not gcov_dir.is_dir():
        print(f"no gcov output in {gcov_dir}")
        return 1

    results = solution_files(gcov_dir)
    if not results:
        print(f"no solution coverage data found in {gcov_dir}")
        return 1

    covered_total = sum(c for c, _ in results.values())
    line_total = sum(t for _, t in results.values())
    print(f"{'solution':<70} {'lines':>7} {'covered':>8}")
    for name in sorted(results):
        covered, total = results[name]
        percent = 100.0 * covered / total if total else 0.0
        print(f"{name:<70} {total:>7} {percent:>7.1f}%")
    percent = 100.0 * covered_total / line_total if line_total else 0.0
    print(f"\n{len(results)} solutions covered, {covered_total}/{line_total} lines ({percent:.1f}%)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
