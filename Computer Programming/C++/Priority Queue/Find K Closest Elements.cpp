class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0;i<arr.size();i++)
        {
            int diff = abs(arr[i]-x);
            pq.push({diff,i});
        }



        priority_queue<int,vector<int>,greater<int>> sort;
        vector<int>ans;
        while(!pq.empty())
        {
            int temp = pq.top().second;
            
            sort.push(temp);
            pq.pop();
            k--;
            if(k==0)
            {
                break;
            }
        }

        while(!sort.empty())
        {
            int index = sort.top();
            ans.push_back(arr[index]);
            sort.pop();
        }
        return ans;
    }
};
