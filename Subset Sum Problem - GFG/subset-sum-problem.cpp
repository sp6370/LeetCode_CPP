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
        //DP
        
        //first let's handle base cases
        
        // handling the sum
        for(int i=0; i<=sum; i++)
        {
            if(i == 0)
            {
                t[0][i] = 1;
            }else
            {
                t[0][i] = 0;
            }
        }
        
        //handling the elements for 0 sum
        for(int i=1; i<=N; i++)
        {
            t[i][0] = 1;
        }
        
        //let's build the table
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(arr[i-1]<=sum)
                {
                    t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
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