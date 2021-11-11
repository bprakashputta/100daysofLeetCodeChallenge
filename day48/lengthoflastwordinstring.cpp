class Solution {
public:
    int lengthOfLastWord(string s) {
        char ch;
        string word="";
        int l=0;
        if(s[0]!=' '){
            word += s[0];
            if(s.length()==1){
                return 1;
            }
        }
        for(int i=1; i<s.length(); i++){
            if(s[i]==' '){
                
                if(s[i-1]!=' '){
                    l = word.length();   
                }
                cout<<i<<":"<<word<<endl;
                word="";
            }else if(i==(s.length()-1)){
                if(s[i]!=' '){
                    word += s[i];
                    l = word.length();   
                return l;
                }
            }else{
                word += s[i];
            }
        }
        if(l==0&&word.length()!=0){
            l = word.length();
        }
    return l;
    }
};