
// OptimalPath.cc

#include <iostream>
using namespace std;

const int maxnum = 100;
const int maxint = 999999;

void Dijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum]){
	// flag of whether node put into Collection S
	bool s[maxnum];
	for(int i=1; i<=n; ++i){
		dist[i] = c[v][i];
		s[i] = 0; //Unused node
		if(dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v; // previous of node i
	}
	dist[v] = 0;
	s[v] = 1;

	// Put node with least dist into collection S
	for(int i=2; i<=n; ++i){
		int tmp = maxint;
		int u = v;
		for(int j=1; j<=n; ++j){
			if(!s[j] && dist[j]<tmp){
				u = j;
				tmp = dist[j];
			}
		}
		s[u] = 1; // Put node u into Collection S
		
		// Update dist table.
		for(int j=1; j<=n; ++j){
			if(!s[j] && c[u][j]<maxint){
				int newdist = dist[u] + c[u][j];
				if(newdist < dist[j]){
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
}

void searchPath(int *prev, int v, int u){
	int queue[maxnum];
	int tot = 1;
	queue[tot++] = u;
	int node = prev[u];
	while(node != v){
		queue[tot++] = node;
		node = prev[node];
	}
	queue[tot] = v;
	for(int i=tot; i>=1; --i){
		if(i != 1)
			cout<<queue[i]<<"-->";
		else
			cout<<queue[i]<<endl;
	}
}

int main(int args, char **argv){
	int dist[maxnum];	// distance from source to current node
	int prev[maxnum];	// previous of current node
	int c[maxnum][maxnum];	// distance between nodes
	int n, line;		// count of nodes and path

	//freopen("input.txt", "r", stdin);
	cout<<"Please Input total node counts:";
	cin>>n;		// input nodes count
	cout<<"Please Input total path counts:";
	cin>>line;	//input path count
	int p, q, len;	// node p, q and the distance between them

	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j)
			c[i][j] = maxint;
	}
	for(int i=1; i<=line; ++i){
		cout<<"Input path "<<i<<" of Total "<<line<<" :"<<endl;
		cin>>p>>q>>len;
		if(len<c[p][q]){
			c[p][q] = len;
			c[q][p] = len;
		}
	}

	for(int i=1; i<=n; ++i)
		dist[i] = maxint;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j)
			cout<<c[i][j];
		cout<<endl;
	}

	Dijkstra(n, 1, dist, prev, c);
	
	cout<<"Distance from source to the destination: "<<dist[n]<<endl;

	cout<<"Path from source to destination:";
	searchPath(prev, 1, n);
}






















































