class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;  //left
        int r=0;  //right
        int zeros=0; 
        int maxLen=0;
        int len;

        int n=nums.size();

        while(r<n){
            if(nums[r]==0){zeros++;}

            if(zeros>k){
                if(nums[l]==0){
                    zeros--;
                    
                }
                l++;
            }
            if(zeros<=k){
                    len=r-l+1;
                    maxLen=max(maxLen,len);
                }
                r++;
        }
        return maxLen;
    }
};