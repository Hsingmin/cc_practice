
// DirectedAcyclicGraph.cc

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

// max number of tasks.
const int N = 1000;
// n is the number of tasks, and m is the number of direct 
// precedence relations between tasks.
int n, m, son[N], topoSort[N], t;
char O[2*N];
vector<int> G[N];

// Initialize Graph and son[N].
void init(){
	for(int i=1; i <= n; ++i){
		G[i].clear();
	}
	memset(son, 0, sizeof(son));
}

int DAGGreedy(){
	
	int u, v;
	// Input vertex n and precedence relation m.
	while(scanf("%d%d", &n, &m) && (n+m)){
		// Clear n Graphs and N indere.
		init();
		for(int i=0; i<m; ++i){
			// Input vertex u and precedence relation. 
			scanf("%d%d", &u, &v);
			// u-->v
			G[u].push_back(v);
			// vertex v indere added
			++son[v];
		}
		// Push vertex with indere=0 into queue.
		int num = n;
		queue<int> q;
		for(int i=1; i<=n; ++i){
			if(!son[i]) q.push(i);
		}
		int pos = 0;
		while(!q.empty()){
			int t = q.front();
			q.pop();
			topoSort[pos++] = t;
			for(int v=0; v<G[t].size(); ++v){
				if(--son[G[t][v]] == 0)
					q.push(G[t][v]);
			}
		}
		for(int i=0; i < pos; ++i){
			if(!i) cout<<topoSort[i];
			else cout<<topoSort[i];
		}
		cout<<endl;
	}
	
	return 0;
}

int DFS_G[N][N], dfs_n, dfs_m, dfs_a, dfs_b;
int dfs_visit[N], dfs_c[N], dfs_topo[N], dfs_t;

bool dfs(int u){
	// Visiting currently.
	dfs_visit[u] = -1;
	for(int v=1; v<=dfs_n; ++v){
		if(DFS_G[u][v]){
			if(dfs_visit[v] == -1) return false;
			else if(!dfs_visit[v] && !dfs(v)) return false;
		}	
	}

	// End visiting process.
	dfs_visit[u] = 1;
	dfs_topo[--dfs_t] = u;
	return true;
}

bool dfsTopoSort(){
	dfs_t = dfs_n;
	// Initialize dfs_visit[N].
	memset(dfs_visit, 0, sizeof(dfs_visit));
	for(int u=1; u<=dfs_n; ++u){
		// dfs_visit[u] == 0 && dfs(u) == false
		if(!dfs_visit[u] && !dfs(u))
			return false;
	}
	return true;
}

int dfsDAG(){

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	while(2 == scanf("%d %d", &dfs_n, &dfs_m) && (dfs_n+dfs_m)){
		// Initialize Directed Acyclic Graph into 2-D array DFS_G.
		memset(DFS_G, 0, sizeof(DFS_G)); // system function
		// dfs_m is group count for vertex-vertex
		for(int i=0; i<dfs_m; ++i){
			scanf("%d %d", &dfs_a, &dfs_b);
			DFS_G[dfs_a][dfs_b] = 1;
		}
		// Topo Sort
		dfsTopoSort();
		//cout<<dfs_topo[0];
		for(int i=0; i<dfs_n; ++i)
			cout<<dfs_topo[i];
		cout<<endl;
		
	}
	return 0;
} 

int main(int args, char **argv){
	
	dfsDAG();
	return 0;
}












































