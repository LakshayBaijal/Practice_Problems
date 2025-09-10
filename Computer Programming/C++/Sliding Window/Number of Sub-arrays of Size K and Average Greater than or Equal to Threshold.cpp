class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int right = 0;
        int left = 0;

        int count = 0;
        int total = 0;

        for(right = 0; right<arr.size();right++)
        {
            total = total + arr[right];
            if(right - left + 1 == k)
            {
                if(total >= k * threshold)
                {
                    count++;
                }
                total -= arr[left];
                left++;
            }
        }

        return count;

    }
};
