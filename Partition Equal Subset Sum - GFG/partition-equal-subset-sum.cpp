// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{

public:

    int t[101][10000];
    
    Solution()
    {
        memset(t, -1, sizeof(t));
    }
    
    int subsetSum(int arr[], int N, int k)
    {
        if(N==0 && k==0)
        {
            return 1;
        }
        
        if(k==0)
        {
            return 1;
        }
        
        if(k!=0 && N==0)
        {
            return 0;
        }
        
        if(t[N][k]!=-1)
        {
            return t[N][k];
        }
        
        if(arr[N-1]<=k)
        {
            t[N][k] = subsetSum(arr, N-1, k-arr[N-1]) || subsetSum(arr, N-1, k);
        }
        else
        {
            t[N][k] = subsetSum(arr, N-1, k);
        }
        
        return t[N][k];
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++)
        {
            sum = sum + arr[i];
        }
        
        if(sum%2!=0)
        {
            return 0;
        }
        
        return subsetSum(arr, N, sum/2);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends