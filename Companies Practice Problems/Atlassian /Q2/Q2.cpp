#include <bits/stdc++.h>
using namespace std;

int maxPerksItems(int cartridges, int dollars, int recycleReward, int perksCost) {

    long long low = 0, high = cartridges;
    long long ans = 0;

    while(low <= high){
        long long x = (low + high) / 2;  

        long long money = dollars + x * recycleReward;
        long long remaining = cartridges - x;

        long long perks = min(remaining, money / perksCost);

        ans = max(ans, perks);

        if(money / perksCost >= remaining)
            low = x + 1;
        else
            high = x - 1;
    }

    return (int)ans;
}

int main() {
    int cartridges, dollars, recycleReward, perksCost;
    cin >> cartridges >> dollars >> recycleReward >> perksCost;

    cout << maxPerksItems(cartridges, dollars, recycleReward, perksCost) << endl;

    return 0;
}
