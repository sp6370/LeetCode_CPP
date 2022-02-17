// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int t[101][10001];
    
    Solution()
    {
        memset(t, -1, sizeof(t));
    }
    
    bool isSubsetSum(int N, int arr[], int sum){
        // let's do top down
        
        // base case
        if(sum == 0 && N == 0)
        {
            return true;
        }
        
        if(sum == 0)
        {
            return true;
        }
        
        if(N==0 && sum!=0)
        {
            return false;
        }
        
        if(t[N][sum]!=-1)
        {
            if(t[N][sum] == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        if(arr[N-1]<=sum)
        {
            t[N][sum] = isSubsetSum(N-1, arr, sum - arr[N-1]) || isSubsetSum(N-1, arr, sum);
        }
        else
        {
            t[N][sum] = isSubsetSum(N-1, arr, sum);
        }
        
        return t[N][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends