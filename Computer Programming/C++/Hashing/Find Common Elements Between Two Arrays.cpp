class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_map<int,int> hash1;
        unordered_map<int,int> hash2;

        int ans1 = 0;
        int ans2 = 0;
        for(auto it : nums1)
        {
            hash1[it] ++;
        }     
        for(auto it : nums2)
        {
            hash2[it] ++;
        }

        for(auto it : nums2)
        {
            if(hash1[it] > 0)
            {
                ans2++;
            }
        }

        for(auto it : nums1)
        {
            if(hash2[it] > 0)
            {
                ans1++;
            }
        }

        return {ans1,ans2};


    }
};
