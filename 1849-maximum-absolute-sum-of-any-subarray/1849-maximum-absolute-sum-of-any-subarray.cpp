// class Solution {
// public:
//     int max_val(int a, int b, int c){
//         if(max(a,b)>c) return max(a,b);
//         return c;
//     }

//     int maxAbsoluteSum(vector<int>& nums) {
//         // vector<int> dp(nums.size());
//         // vector<int> dp1(nums.size());
//         // dp[0] = nums[0];
//         // dp1[0] = nums[0];
//         // int maxx = INT_MIN;
//         // for(int i=1; i<nums.size(); i++){
//         //     if(abs(dp[i-1]+nums[i])>=abs(nums[i])) dp[i] = dp[i-1]+nums[i];
//         //     else dp[i] = nums[i];
//         //     dp1[i] = max(dp1[i-1]+nums[i], nums[i]);
//         //     maxx = max_val(abs(dp[i]), abs(dp1[i]), maxx);
//         // }
//         // return maxx;
//         // int maxx = INT_MIN;
//         // for(int i=0; i<nums.size(); i++){
//         //     int sum = 0;
//         //     for(int j=i; j<nums.size(); j++){
//         //         sum += nums[j];
//         //         maxx = max(abs(sum), maxx);
//         //     }
//         // }
//         // return maxx;
        
//     }
// };

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int i=1,j=0,ans=nums[0],max_ans=abs(nums[0]);
        while(i<nums.size())
        {
            if((ans>0&&ans+nums[i]<=0)||(ans<0&&ans+nums[i]>=0))
            {
                ans+=nums[i];
                int mx_i=j,mx=ans;
                while(j<=i)
                {
                    ans-=nums[j];
                    j++;
                    if(abs(ans)>abs(mx))
                    {
                        mx=ans;
                        mx_i=j;
                    }
                }
                j=mx_i;
                ans=mx;
                cout<<j<<" "<<ans<<endl;
            }
            else
            ans+=nums[i];
            max_ans=max(max_ans,abs(ans));
            i++;
        }
        return max_ans;
    }
};