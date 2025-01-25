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
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            count=count+(r-l+1);
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //for this we have to calculate the No. of subarray where the sum<=goal 
        //and then sub it with the func having goal-1 ...then we got our ans 

        int ans= numSubarraysWithSumLessThanGoal(nums,goal)-numSubarraysWithSumLessThanGoal(nums,goal-1);

        return ans;
    }
};