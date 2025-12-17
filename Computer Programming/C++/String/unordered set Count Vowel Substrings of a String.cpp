class Solution {
public:
    int countVowelSubstrings(string word) 
    {
        int n = word.size();
        int count = 0;

        for (int i = 0;i < n;i++)
        {
            if(!vowel(word[i]))
            {
                continue;
            }
            unordered_set<char> sp;
            for(int j = i;j<n && vowel(word[j]);j++)
            {
                sp.insert(word[j]);
                if(sp.size() == 5)
                {
                    count++;
                }
            }
        }

        return count;
    }

    bool vowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        return false;
    }


};
