class Solution {
public:
    
    int bSearch(vector<char> arr, char target, int start, int end)
    {
        int res = -1;
        int val = INT_MAX;
        
        while(start<=end)
        {
            int mid = start + (end - start)/2;
            
            if(arr[mid] == target)
            {
                if(mid+1<arr.size() && arr[mid+1]!=arr[mid])
                {
                    return mid+1;
                }
                
            }
            
            if(arr[mid] > target)
            {
                if(arr[mid]<val)
                {   
                    res = mid;
                    val = arr[mid];
                }
                end = mid-1;
            }
            else
            {
                start = mid + 1;
            }
        }
        
        return res;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int pos = bSearch(letters, target, 0, letters.size()-1);
        
        if(pos == -1)
        {
            return letters[0];
        }
        
        return letters[pos];
    }
};