//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int l=0; //left
        int r=0; //right
        
        int maxLen=0;
        int len;
        int countNum=0; // in order to track distinct num is atmost 2
        int n=arr.size();
        
        map<int,int>mpp;
        while(r<n){
             mpp[arr[r]]++;
            
            while(mpp.size()>2){
                mpp[arr[l]]--; //decrease the count of the left pointer
                if(mpp[arr[l]]==0){
                    mpp.erase(arr[l]);
                }
                l++;
                
            }
            
            // calculate the len
             
                len=r-l+1;
                maxLen=max(maxLen,len);
            r++;
            }
            
            
        return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends