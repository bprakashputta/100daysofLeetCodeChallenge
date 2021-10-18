#include<iostream>
#include<string>
using namespace std;

// Remove Colored Pieces if Both Neighbors are the Same Color 
// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color
bool winnerOfGame(string colors) {
    if(colors.length()<3){
        return false;
    }   
    
    int Apair=0,Bpair=0;
    for(long long i=1; i<colors.length()-1; i++){
        if(colors[i] == 'A' && colors[i]==colors[i-1] && colors[i]==colors[i+1]){
            Apair++;
        }
    
        if(colors[i] == 'B' && colors[i]==colors[i-1] && colors[i]==colors[i+1]){
            Bpair++;
        }
    }
    cout<<"Apir"<<Apair<<endl;
    cout<<"Bpir"<<Bpair<<endl;
    
    if(Apair == 0){
        return false;
    }else if(Apair !=0 && Apair > Bpair){
        return true;
    }else{
        return false;
    }
return false;    
}