#include<bits/stdc++.h>
using namespace std;
int vis[8][8];
int lev[8][8];
int makex(string s){
    return s[0]-'a';
}
int makey(string s){
    return s[1]-'1';
}
void reset(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            lev[i][j]=0;
            vis[i][j]=0;
        }
    }
}

vector<pair<int,int>> movements={
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1}
};

bool isValid(int x,int y){
    if(x>=0&&y>=0&&x<8&&y<8){
        return true;
    }
    return false;
}


int bfs(string s1,string s2){
int sourcex=makex(s1);
int sourcey=makey(s1);
int destx=makex(s2);
int desty=makey(s2);

queue<pair<int,int>> q;
q.push({sourcex,sourcey});
while(!q.empty()){
    pair<int,int> p=q.front();
    q.pop();
    vis[sourcex][sourcey]=1;
for(auto movement:movements){
    int x=p.first+movement.first;
    int y=p.second+movement.second;
    if(isValid(x,y)){
        if(vis[x][y]==0){
            q.push({x,y});
            vis[x][y]=1;
            lev[x][y]=lev[p.first][p.second]+1;
        }
    }
}

}

return lev[destx][desty];

}
int main(){
    int n;
    cin>>n;
    while(n--){
        reset();
        string s1,s2;
        cin>>s1>>s2;
        cout<<bfs(s1,s2);
    }
    return 0;
}
