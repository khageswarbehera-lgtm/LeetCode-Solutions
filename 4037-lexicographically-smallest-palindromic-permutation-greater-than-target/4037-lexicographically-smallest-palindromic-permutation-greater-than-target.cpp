class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        // Required by the problem statement.
        string calendrix = s;

        int n = s.size();

        // Count characters.
        vector<int> cnt(26, 0);

        for (char c : s)
        {
            cnt[c - 'a']++;
        }

        // Check whether palindrome is possible.
        int oddCount = 0;
        char middle = '\0';

        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] % 2 == 1)
            {
                oddCount++;
                middle = char('a' + i);
            }
        }

        if (oddCount > 1)
            return "";

        // Number of characters needed in left half.
        int halfLen = n / 2;

        // Characters available for left half.
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++)
        {
            halfCnt[i] = cnt[i] / 2;
        }

        string left;

        /*
        --------------------------------------------------------
        Feasibility function

        We already selected 'left'.

        Fill remaining positions with the LARGEST possible
        characters.

        If this largest possible palindrome is still <= target,
        then no completion can work.

        Otherwise, a valid completion exists.
        --------------------------------------------------------
        */
        auto canMakeGreater = [&]() -> bool {

            string largestLeft = left;

            // Put remaining characters in descending order.
            for (int c = 25; c >= 0; c--)
            {
                largestLeft += string(
                    halfCnt[c],
                    char('a' + c)
                );
            }

            // Construct largest possible palindrome.
            string candidate = largestLeft;

            if (middle != '\0')
            {
                candidate += middle;
            }

            for (int i = (int)largestLeft.size() - 1;
                 i >= 0;
                 i--)
            {
                candidate += largestLeft[i];
            }

            return candidate > target;
        };


        /*
        --------------------------------------------------------
        Build the answer from left to right.

        Try smallest possible character first.
        --------------------------------------------------------
        */
        for (int pos = 0; pos < halfLen; pos++)
        {
            bool found = false;

            for (int c = 0; c < 26; c++)
            {
                // No character of this type available.
                if (halfCnt[c] == 0)
                    continue;

                // Temporarily choose this character.
                halfCnt[c]--;
                left.push_back(char('a' + c));

                // Can this choice eventually produce
                // a palindrome greater than target?
                if (canMakeGreater())
                {
                    found = true;
                    break;
                }

                // This character cannot lead to a solution.
                left.pop_back();
                halfCnt[c]++;
            }

            // No possible character at this position.
            if (!found)
                return "";
        }


        /*
        --------------------------------------------------------
        Construct final palindrome.
        --------------------------------------------------------
        */

        string answer = left;

        if (middle != '\0')
        {
            answer += middle;
        }

        reverse(left.begin(), left.end());

        answer += left;

        return answer > target ? answer : "";
    }
};