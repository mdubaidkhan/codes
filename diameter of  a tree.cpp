

/* this the code to find the diameter of a tree it uses depth first search */



#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> tr[N];
vector<int> depth;

void dfs(int vertex,int parent =-1 ){
	for(int child:tr[vertex]){
		if(child==parent)
		continue;
		depth[child]=depth[vertex]+1;
		dfs(child,vertex);
	}
}
int main(){
	
	int n;
	int e;
	cin>>n>>e;
	
	depth=vector<int>(n,0);
	for(int i=1;i<=e;i++){
		int a,b;
		cin>>a>>b;
		tr[a].push_back(b);
		tr[b].push_back(a);
	}
	dfs(1,-1);
	int max=-1;
	int max_node;
	for(int i=1;i<=n;i++){
		if(depth[i]>max)
		{
			max=depth[i];
			max_node=i;
		}
		depth[i]=0;
	}
	dfs(max_node);
	max=-1;
	for(int i=0;i<=n;i++){
		if(max<depth[i])
		max=depth[i];
	}
	cout<<max<<endl;
	return 0;


}
