class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string>current;

        function(ans,current,s,0);
        return ans;
    }

    void function(vector<vector<string>>&ans,vector<string>&current,string s,int start)
    {
        if(s.size()==start)
        {
            ans.push_back(current);
            return;
        }

        for(int end = start;end<s.size();end++)
        {
            if(ispalindrome(s,start,end))
            {
                current.push_back(s.substr(start,end - start + 1));
                function(ans,current,s,end+1);
                current.pop_back();
            }
        }
        return;
    }

    bool ispalindrome(string s,int left,int right)
    {
        while(left < right)
        {
            if(s[left++] != s[right--])
            {
                return false;
            }

        }
        return true;
    }


};
