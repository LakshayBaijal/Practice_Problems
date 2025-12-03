#include <bits/stdc++.h>
using namespace std;

vector<int> waysToChooseSum(int lowLimit, int highLimit) 
{

    // TODO: write logic here
    vector<int> hash(200, 0);   // Enough size for digit sums


    for(int index = lowLimit;index<=highLimit;index++)
    {
        int total = 0;
        int k = index;

        while(k>0)
        {
            int temp = k%10;
            k = k/10;
            total = total + temp;
        }

        hash[total] ++;
    }

    int maximum = *max_element(hash.begin(),hash.end());
    int ans = 0;
    for(auto it : hash)
    {
        if(maximum == it)
        {
            ans ++;
        }
    }

    return {maximum,ans};
}

int main() {
    int lowLimit, highLimit;
    cin >> lowLimit >> highLimit;

    vector<int> result = waysToChooseSum(lowLimit, highLimit);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
