class Solution {
public:
    int subarraysWithLessThanKDistinct(vector<int>& nums, int k){
        int l=0; //left
        int r=0; //right
        int count=0;
        map<int,int>mpp;

        int n=nums.size();
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            count=count+(r-l+1); //(r-l+1) {bcoz subarrays also generate}
            r++;
        }
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //similar to binary subarray sum
        int ans=subarraysWithLessThanKDistinct(nums,k)-subarraysWithLessThanKDistinct(nums,k-1);
        return ans;
    }
};