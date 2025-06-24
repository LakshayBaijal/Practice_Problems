class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> numbers;
        for(int i=1;i<=n;i++)
        {
            numbers.push_back(i);
        }
        vector<vector<int>> comb;
        vector<int> current; 
        function(comb,current,numbers,k,n-1);    
        return comb;
    }

    void function(vector<vector<int>> &comb,vector<int> &current,vector<int> &numbers,int k,int index)
    {
        if(k==0)
        {
            comb.push_back(current);
            return;
        }
        if(index < 0)
        {
            return;
        }
        function(comb,current,numbers,k,index-1);
        current.push_back(numbers[index]);
        function(comb,current,numbers,k-1,index-1);
        current.pop_back();
        return;

    }
};
