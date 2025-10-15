class Solution {
public:
    bool canCross(vector<int>& stones) 
    {
        if(stones[1] - stones[0] > 1)
        {
            return false;
        }

        return function(0,1,stones);    
    }

    bool function(int index,int jump,vector<int>&stones)
    {
        if(index==stones.size()-1)
            return true;

        bool ans = false;
        for(int i = index + 1; i<stones.size();i++)
        {
            int dist = stones[i] - stones[index];

            if (dist > jump + 1)
                break;

            if (dist == jump - 1 || dist == jump || dist == jump + 1)
            {
                if (function(i, dist, stones))
                    return true;
            }
        }

        return ans;
    }


};
