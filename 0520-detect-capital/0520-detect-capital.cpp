class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        for(char x:word)
        {
            if(int(x)>=65 && int(x)<=90)
            count++;
        
        }
        if(count==word.length())
        return true;
        if(count==0)
        return true;
        if(count==1 && (int(word[0])>=65 && int(word[0])<=90))
        return true;
        return false;
        
    }
};