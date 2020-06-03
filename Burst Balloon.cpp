/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1), nums.push_back(1);
        for(int i=nums.size()-1; i>0; i--)  nums[i]=nums[i-1];
        nums[0]=1;
        int n=nums.size(), prod=0, ans=0, left, right;
        vector<vector<int>> dp(n+1, vector<int>(n, 0));
        for(int l=1; l<=n-2; l++)
        {
            for(int i=1; i<n-l; i++)
            {
                prod=0;
                left=i-1, right=i+l;
                for(int j=i; j<i+l; j++)
                {
                    prod=max(prod, nums[left]*nums[j]*nums[right]+dp[j-i][i]+dp[i+l-j-1][j+1]);
                }
                dp[l][i]=prod;
                //cout<<dp[l][i]<<" ";
                ans=max(ans, dp[l][i]);
            }
            //cout<<endl;
        }
        return ans;
    }
};