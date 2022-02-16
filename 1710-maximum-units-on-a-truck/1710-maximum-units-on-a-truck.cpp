class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        // lets sort the 2D-array by number of units per box
        
        sort(boxTypes.begin(), boxTypes.end(), 
             [](const vector<int>&a, const vector<int>&b)
             {
                 return a[1]<b[1];
             });
        
        //then keep selecting boxes with max units until we hit truck size
        int boxPlaced = 0;
        int total = 0;
        while(boxPlaced<truckSize && boxTypes.size()>0)
        {
            total = total + boxTypes.back()[1];
            ++boxPlaced;
            --boxTypes.back()[0];
            if(boxTypes.back()[0] == 0)
            {
                boxTypes.pop_back();
            }
        }
        return total;   
    }
};