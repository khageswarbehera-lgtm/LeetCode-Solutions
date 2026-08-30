class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1=word1.length();
        int l2=word2.length();
        string result;
        int left=0;
        int right=0;
        while(left<l1 && right<l2)
        {
            result+=word1[left++];
            result+=word2[right++];

        }
        while(left<l1)
        result+=word1[left++];
        while(right<l2)
        result+=word2[right++];

        return result;


        
    }
};