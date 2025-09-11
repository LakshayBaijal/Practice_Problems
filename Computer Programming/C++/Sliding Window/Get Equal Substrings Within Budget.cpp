class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int left = 0;
        int right = 0;

        int n = s.size();
        int cost = 0;
        int maximum = 0;
        for(right = 0;right < n;right ++)
        {
            cost += abs(t[right] - s[right]);

            while(cost>maxCost)
            {
                cost -= abs(t[left] - s[left]);
                left++;
            }
            
            maximum = max(maximum,right - left + 1);
        }       
        return maximum;
    }
};
