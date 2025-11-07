Google Online Assessment (OA) - Pick Up Coupons
You are given a scratchcard consisting of a row of non-negative integers. To win the scratch game, you need to scratch at least 2 numbers of the same value. You can only scratch consecutive numbers from the card. Scratching each number costs 1 dollar. Return the minimum cost to win the game, or -1 if winning is not possible.

Examples
Example 1:
Input:
[1, 3, 4, 2, 3, 4, 5]

Output: 4
Explanation:
You can scratch either [3, 4, 2, 3] or [4, 2, 3, 4].

Example 2:
Input:
[2, 5, 0, 3, 7]

Output: -1 


#include <bits/stdc++.h>
using namespace std;
int min_cost_to_win(std::vector<int>& nums) 
{
    // WRITE YOUR BRILLIANT CODE HERE

    int minimum = INT_MAX;
    unordered_map<int, int> hash;

    for(int i = 0;i<nums.size();i++)
        {
            if (hash.find(nums[i]) != hash.end())
            {
                int temp = i - hash[nums[i]] + 1;
                hash[nums[i]] = i;
                if (temp < minimum)
                {
                    minimum = temp;
                }
            }
            else
            {
                hash[nums[i]] = i;
            }
        }
    if(minimum == INT_MAX)
    {
        return -1;
    }
    return minimum;
}
