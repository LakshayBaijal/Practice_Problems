class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        priority_queue<int>pq;

        for(auto it : piles)
        {
            pq.push(it);
        }    

        while(!pq.empty())
        {
            int ele = pq.top();
            if(ele % 2 != 0)
            {
                ele = ele / 2 + 1;
            }
            else
            {
                ele = ele / 2;
            }
            pq.pop();

            pq.push(ele);
            k--;
            if(k==0)
            {
                int total = 0;
                while(!pq.empty())
                {
                    total += pq.top();
                    pq.pop();
                }
                return total;
            }
        }

        return 0;

    }
};
