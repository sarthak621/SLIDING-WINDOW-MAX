class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum=0; // left sum
        int rSum=0; // right Sum
        int maxSum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
              lSum+=cardPoints[i];
              
        }
        maxSum=lSum;

        int rightIndex=n-1;
        for(int i=k-1;i>=0;i--){
            lSum=lSum-cardPoints[i];
            rSum=rSum+cardPoints[rightIndex];
            rightIndex--;

            maxSum=max(maxSum,(lSum+rSum));
        }

        return maxSum;
    }
};