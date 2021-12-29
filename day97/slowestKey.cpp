class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int mx_duration=0, duration=0;
        char result;
        for(int i=0; i<keysPressed.length(); i++){
            if(i==0){
                duration = releaseTimes[i]-0;
                mx_duration = duration;
                result = keysPressed[i];
            }else{
                duration = releaseTimes[i]-releaseTimes[i-1];   
                if(duration == mx_duration){
                    result = max({keysPressed[i], result});
                }else if(duration > mx_duration){
                    mx_duration = duration;
                    result = keysPressed[i];
                }
            }
        }
    return result;
    }
};