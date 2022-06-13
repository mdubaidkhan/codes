#include<bits/stdc++.h>
using namespace std;
vector<int> tr[100000];
vector<int> p;

void dfs(int vertex,int par=-1){
    p[vertex]=par;
    for(int child:tr[vertex]){
        if(child==par)
        continue;
        dfs(child,vertex);
    }
}

void make_vec(int i,vector<int> &vec){
    while(i!=-1){
        vec.push_back(i);
        i=p[i];
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    p=vector<int>(n,-1);
    for(int i=1;i<=e;i++){
        int a,b;
        cin>>a>>b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    dfs(1);
    vector<int> vec1;
    vector<int> vec2;

    make_vec(4,vec1);
   make_vec(5,vec2);
   int minl=min(vec1.size(),vec2.size());
   int sol;
   for(int i=0;i<minl;i++){

    if(vec1[i]==vec2[i]){
        sol=vec1[i];
        break;
    }
    
   }
   cout<<sol;
   return 0;

}
