// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C

// Function to find floor of K
// arr[]: integer array of size N
// N: size of arr[]
// K: element whose floor is to find

int Bsearch(long long int arr[], int start, int end, int target)
{
    int res = -1;
    int rval = -1;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        
        if(arr[mid] == target)
        {
            return mid;
        }
        
        if(arr[mid]<target)
        {
            if(arr[mid]>rval)
            {
                rval = arr[mid];
                res = mid;
            }
            start = mid + 1;
        }
        else
        {
            end = mid-1;
        }
    }
    return res;
}

int findFloor(long long int arr[], int N, long long int K) {
    
    // if(arr[0]>K)
    // {
    //     return -1;
    // }
    
    // if(arr[N-1]<=K)
    // {
    //     return arr[N-1];
    // }
    
    int ans = Bsearch(arr, 0, N-1, K);
    return ans;
}

// { Driver Code Starts.

int main() {
	
	long long int t;
	scanf("%lld", &t);
	
	while(t--){
	    int n;
	    scanf("%d", &n);
	    long long int x;
	    scanf("%lld", &x);
	    
	    long long int *arr;
		arr = (long long int *)malloc(n * sizeof(long long int));
	    
	    for(int i = 0;i<n;i++){
	        scanf("%lld", &arr[i]);
	    }
	    printf("%d\n", findFloor(arr, n, x) );
	   
	}
	
	return 0;
}

  // } Driver Code Ends