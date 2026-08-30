class Solution {
public:
    bool backspaceCompare(string s, string t) {

        int i = s.size() - 1;
        int j = t.size() - 1;

        int skip1 = 0;
        int skip2 = 0;

        while(i >= 0 || j >= 0)
        {
            // Find next valid character in s
            while(i >= 0)
            {
                if(s[i] == '#')
                {
                    skip1++;
                    i--;
                }
                else if(skip1 > 0)
                {
                    skip1--;
                    i--;
                }
                else
                {
                    break;
                }
            }

            // Find next valid character in t
            while(j >= 0)
            {
                if(t[j] == '#')
                {
                    skip2++;
                    j--;
                }
                else if(skip2 > 0)
                {
                    skip2--;
                    j--;
                }
                else
                {
                    break;
                }
            }

            // One string has a valid character, other doesn't
            if(i >= 0 && j < 0)
                return false;

            if(i < 0 && j >= 0)
                return false;

            // Both have valid characters
            if(i >= 0 && j >= 0 && s[i] != t[j])
                return false;

            // Move after comparing
            i--;
            j--;
        }

        return true;
    }
};