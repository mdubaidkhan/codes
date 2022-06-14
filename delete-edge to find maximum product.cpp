#include<bits/stdc++.h>
using namespace std;

vector<int> tr[100000];
int val[100000];
int sum_val[100000];

dfs(int vertex,int par=-1){
    sum_val[vertex]+=val[vertex];
    for(auto child:tr[vertex]){
        if(child==par)
        continue;
        dfs(child,vertex);
        sum_val[vertex]+=sum_val[child];
    }
}


int main(){
int n,e;
cin>>n>>e;
for(int i=0;i<e;i++){
    int a,b;
    cin>>a>>b;
    tr[a].push_back(b);
    tr[b].push_back(a);
}
for(int i=1;i<=n;i++){
cin>>val[i];
}
dfs(1);
int max=0;
for(int i=2;i<=n;i++){
    int part1=sum_val[i];
    int part2=sum_val[1]-part1;
    if(max<part1*part2)
    max=part1*part2;
}
cout<<max;
return 0;

}
