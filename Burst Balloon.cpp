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