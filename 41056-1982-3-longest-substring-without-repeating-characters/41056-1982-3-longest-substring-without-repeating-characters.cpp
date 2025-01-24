class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //two pointer approach
        vector<int>mpp(256,-1);
        int l=0; //left
        int r=0; //right
        int maxLen=0;
        int len;
        int n=s.size(); //size of string
        while(r<n){
            if(mpp[s[r]]!=-1){
                //the character is present in the map then we need to update the left pointer

                //checking the character is greater than left pointer or not
                if(mpp[s[r]]>=l){
                        l=mpp[s[r]]+1;
                }
            }
            
            //checking the current length
            len=r-l+1;
            maxLen=max(len,maxLen);
            
            //updating the hash value of the right pointer
            mpp[s[r]]=r;
            r++;
        }
        return maxLen;

    }
};