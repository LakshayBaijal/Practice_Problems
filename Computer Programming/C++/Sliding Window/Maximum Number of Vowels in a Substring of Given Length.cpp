class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int count = 0;
        int right = 0;
        int left = 0;
        int maximum = 0;

        for(right = 0; right<s.size();right++)
        {
            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u')
            {
                count ++;
            }
            if(right - left >= k)
            {
                if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u')
                {
                    count--;
                }
                left++;
            }
            maximum = max(maximum,count);
        }

        return maximum;

    }
};
