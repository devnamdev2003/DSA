#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string> words) {
    int arr[26]={0};
    for(int i=0;i<allowed.size();i++){
        arr[allowed[i]-'a']++;

    }
    int ans=0;
    bool flag=0;
    for(int i=0;i<words.size();i++){
        for(int j=0;j<words[i].size();j++){
            if(arr[words[i][j]-'a']==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            ans++;
        }
        else{
            flag=0;
        }
    }
    return ans;
    }
};

int main(){
      Solution obj;
      cout<<obj.countConsistentStrings("ab",{"ad","bd","aaab","baa","badab"});
}