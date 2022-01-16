// { Driver Code Starts


#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int findOccurence(int arr[], int n, int x, bool first)
	{
	    
	    int start = 0;
	    int begin = 0;
	    
	    int end = n-1;
	    int last = n-1;
	    
	    while(start<=end)
	    {
	        int mid = start + (end - start)/2;
	        
	        if(x == arr[mid])
	        {
	            if(first)
	            {
    	            if(mid == begin || arr[mid-1]!=arr[mid])
    	            {
    	                return mid;
    	            }
    	            
	                end = mid - 1;
	            }
	            else
	            {
    	            if(mid == last || arr[mid+1]!=arr[mid])
    	            {
    	                return mid;
    	            }
    	            
    	            start = mid + 1;
    	        }
    	        
    	        continue;
	        }
	        
	        if(x > arr[mid])
	        {
	            start = mid+1;
	        }
	        else
	        {
	            end = mid-1;
	        }
	    }
	    
	    return -1;
	}
	
	
	int count(int arr[], int n, int x) {
	    
	    int fo =  findOccurence(arr, n , x, true);
	    int lo = findOccurence(arr, n, x, false);
	    
	    if(fo == -1)
	    {
	        return 0;
	    }
	    
	    return lo - fo + 1;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends