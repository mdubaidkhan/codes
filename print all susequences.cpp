#include<bits/stdc++.h>
using namespace std;
void subSeq(string s,string s1){
    if(s.empty()){
        cout<<s1<<endl;
        return;
    }
    subSeq(s.substr(1),s1+s[0]);
    subSeq(s.substr(1),s1);
    
}
int main(){
    string s;
    cin>>s;
    string s1="";
    subSeq(s,s1);
    return 0;
}



/* approach two */

#include<bits/stdc++.h>
using namespace std;

void subSeq(string s,int ind=-1,string curr=""){
   if(ind==s.size()){

    return ;
   }

   if(!curr.empty()){
    cout<<curr<<endl;
   }
   for(int i=ind+1;i<s.size();i++){
    curr+=s[i];
    subSeq(s,i,curr);
    curr=curr.erase(curr.size()-1);
   }
    
}
int main(){
    string s;
    cin>>s;
    string s1="";
    subSeq(s);
    return 0;
}
