class Solution {
public:
    
    int numSubarraysWithSumLessThanGoal(vector<int>& nums, int goal){
        
        if(goal<0) return 0;
        int l=0; //left
        int r=0; //right
        int sum=0;
        int count=0;

        int n=nums.size();

        while(r<n){
            sum+=nums[r]%2;
            while(sum>goal){
                sum=sum-nums[l]%2;
                l++;
            }
            count=count+(r-l+1);
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        //approach: take the even no. as 0 and odd as 1
        //and apply {930. Binary Subarrays With Sum} method

         int ans= numSubarraysWithSumLessThanGoal(nums,k)-numSubarraysWithSumLessThanGoal(nums,k-1);

        return ans;
    }
};