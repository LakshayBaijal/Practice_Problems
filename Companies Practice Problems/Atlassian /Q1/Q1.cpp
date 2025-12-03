#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long maximumProfit(vector<int> inventory, long order) 
{
    priority_queue<int> pq;
    
    for(auto it : inventory)
    {
        pq.push(it);
    }

    int profit = 0;

    while(order>0)
    {
        int greatest = pq.top();
        profit = greatest + profit;
        pq.pop();
        pq.push(greatest - 1);
        order--;

        if(greatest - 1 > 0)
        pq.push(greatest - 1);
    }

    return profit;
}

int main() {
    int n;
    cin >> n;

    vector<int> inventory(n);
    for(int i = 0; i < n; i++) {
        cin >> inventory[i];
    }

    long order;
    cin >> order;

    long result = maximumProfit(inventory, order);
    cout << result << endl;

    return 0;
}
