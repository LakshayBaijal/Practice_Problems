class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> comb;
        vector<int> current;
        vector<int> number;

        for(int i=1;i<=9;i++)
        {
            number.push_back(i);
        }
        int index = 0;
        function(comb,current,number,k,n,index);   
        return comb; 
    }

    void function(vector<vector<int>>&comb, vector<int>&current,vector<int>&number,int k,int n,int index)
    {
        if(k==0 && n==0)
        {
            comb.push_back(current);
            return;
        }

        if(k<0 || n<0 || index > 9)
        {
            return;
        }

        function(comb,current,number,k,n,index+1);
        current.push_back(number[index]);
        function(comb,current,number,k-1,n-number[index],index+1);
        current.pop_back();
        return;

    }
};
