using namespace std;

class Solution {
public:
        
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort the intervals based on ending time
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        
        vector<vector<int>> result;
        
        for(int i=0; i<intervals.size(); i++)
        {
            if(result.empty() || result.back()[1] < intervals[i][0])
            {
                result.push_back(intervals[i]);
            }
            else
            {   
                result.back()[1] = max (result.back()[1], intervals[i][1]);
                result.back()[0] = min(result.back()[0], intervals[i][0]);
            }
        }
        return result;
    }
};