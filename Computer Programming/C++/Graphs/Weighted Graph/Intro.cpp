#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n  =  3;
    vector<vector<pair<int,int>>> adjlist(n);
    adjlist[0].push_back({1,2});
    adjlist[1].push_back({2,2});
    adjlist[2].push_back({1,1});

    for(int i = 0;i<n;i++)
    {
        cout << " node " <<i;
        for(auto it : adjlist[i])
        {
            cout << " Edge connected "<<it.first;
            cout << " Edge Weight "<< it.second;
            cout<< endl;
        }
    }

    return 0;
}
