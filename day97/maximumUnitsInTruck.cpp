class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        for(int i=0; i<boxTypes.size(); i++){
            int temp = boxTypes[i][0];
            boxTypes[i][0] = boxTypes[i][1];
            boxTypes[i][1] = temp;
        }
        sort(boxTypes.begin(), boxTypes.end());
        int units=0;
        int i=boxTypes.size()-1;
        while(truckSize>0 && i>=0){
            int minVal = min({boxTypes[i][1], truckSize});
            units += minVal*boxTypes[i][0];
            truckSize -= boxTypes[i][1];
            i--;
            // if(!truckSize)break;
        }
    return units;
    }
};