class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0; //left
        int r=0; //right

        int maxLen=0;
        int maxFreq=0;
        int n=s.size();
        vector<int>hash(26,0);

        // {No. of characters we have to change -> len-maxFreq}

        while(r<n){
            hash[s[r]-'A']++;
            maxFreq=max(maxFreq,hash[s[r]-'A']);

            int len=r-l+1;

            if(len-maxFreq>k){
                hash[s[l]-'A']--;
                l=l+1;
            }
           
            len=r-l+1;
            if(len-maxFreq<=k){
                maxLen=max(maxLen,len);
            }
            r++;
        }
        return maxLen;
    }
};