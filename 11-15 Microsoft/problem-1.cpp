/*
Link : https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
Author : Yuvraj Parashar
*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    // DP matrix will tell about which subset sums are possible from [0 to sum] 
    // and then we will chech that on which subset sum it is minimum possible difference
    // suppose total sum of array is 20 and there is 12 subset sum possible then remaining subset sum
    // can be obtained using (total_sum - 1st_subset_sum)
    // so difference can be obtained using
    // 1st_subset_sum - (total_sum - 1st_subset_sum)
    vector<int> isSubsetSumPossible(int arr[], int n, int sum){
        
        bool dp[n+1][sum+1];
        
        // Initialization
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(i == 0){
                    dp[i][j] = false;
                }
                if(j == 0){
                    dp[i][j] = true;
                }
            }
        }
        
        // Fill the DP Matrix
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        vector<int> possible_subset_sums;
        for(int j = 0; j <= sum; j++){
            if(dp[n][j]){
                possible_subset_sums.push_back(j);
            }
        }
        return possible_subset_sums;
    }
    
	int minDifference(int arr[], int n)  { 
	    // finding total_sum of given array
	    int range = 0;
	    for(int i = 0; i < n; i++){
	        range += arr[i];
	    }
	    
	    // This vector will have all possible subset sums
	    // then we will check minimum difference
	    // 1st subset sum => vector [i]
	    // 2nd subset sum => total_array_sum - vector[i]
	    // now find the minimum difference
	    vector<int> possible_subsets_sum = isSubsetSumPossible(arr, n, range);
	    int minimum_diff = INT_MAX;
	    for(int i = 0; i < possible_subsets_sum.size(); i++){
	       int fst_sss = possible_subsets_sum[i];
	       int scnd_sss = range - possible_subsets_sum[i];
	       minimum_diff = min(minimum_diff, abs(fst_sss-scnd_sss));
	    }
	    return minimum_diff;
	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends