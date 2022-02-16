// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    int t[1001][1001];
    
    public:
    Solution()
    {
        memset(t, -1, sizeof(t));
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       if(n == 0 || W == 0)
       {
           return 0;
       }
       
       
       if(t[n][W]!=-1)
       {
           return t[n][W];
       }
       
       //current item can be considered
       if(wt[n-1]<=W)
       {    
           //case 1.1 Item is included
           //case 1.2 Item is not included
            t[n][W] = max( (val[n-1] + knapSack(W-wt[n-1], wt, val, n-1)),knapSack(W, wt, val, n-1));
       }
       else
       {
            t[n][W] = knapSack(W, wt, val, n-1);
       }
       
       return t[n][W];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends