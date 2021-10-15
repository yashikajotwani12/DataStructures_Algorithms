
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define setbits(n) __builtin_popcountll(n);
vector<int> adj[100005];
int vis[100005]; 
 
void dfs(int node) {
	cout << node << " "; 
	vis[node] = 1; 
 
	// traverse for all adjacent nodes
	// and go in depth for reach 
	/// {2, 7, 9}
	for(auto it: adj[node]) {
		if(vis[it] == 0) {
			dfs(it); 
		}
	}
}
void bfs(int node) {
	vis[node] = 1; 
	queue<int> q; 
	q.push(node); 
 
	while(!q.empty()) {
		int node = q.front(); 
		q.pop(); 
		cout << node << " "; 
 
		for(auto it : adj[node]) {
			if(!vis[it]) {
				vis[it] = 1; 
				q.push(it); 
			}
		}
	}
}
void bfsSolve() {
	int n, m;
	cin >> n >> m; 
 
	for(int i = 1; i<=m; i++) {
		int u, v;
		cin >> u >> v; 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}
 
	for(int i = 1;i<=n;i++) {
		if(vis[i] == 0) {
			bfs(i); 
		}
	}
}
 
int findMinimumMoves(int start, int end, int arr[], int n) {
	int vis[end+1]; 
	vis[start] = 1; 
 
	queue<pair<int,int>> q; 
	q.push({start, 0}); 
 
	while(!q.empty()) {
		int node = q.front().first; 
		int steps = q.front().second; 
 
		if(node == end) return steps; 
 
		q.pop(); 
 
		for(int i = 0;i<n;i++) {
			int dest = node * arr[i]; 
			if(dest <= end && !vis[dest]) {
				q.push({dest, steps+1}); 
				vis[dest] = 1; 
			}
		}
	}
 
	return -1; 
}
 
void dfsSolve() {
	int n, m;
	cin >> n >> m; 
 
	for(int i = 1; i<=m; i++) {
		int u, v;
		cin >> u >> v; 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}
 
	for(int i = 1;i<=n;i++) {
		if(vis[i] == 0) {
			dfs(i); 
		}
	}
 
 
}
 
int vis[100005]; 
 
bool bfsCycle(int node) {
	queue<pair<int,int>> q;
	q.push({node, 0}); 
	vis[node] = 1; 
 
	while(!q.empty()) {
		int node = q.front().first; 
		int par = q.front().second; 
		q.pop();
 
		for(auto it : adj[node]) {
			if(vis[it] == 0) {
				q.push({it, node}); 
				vis[it] = 1; 
			}
			else if(vis[it] == true && it != par) {
				return true; 
			}
		}
	}
	return false; 
}
void bfsCycleChecked() {
	bool fl = false; 
	for(int i = 1;i<=n;i++) {
		if(vis[i] == 0) {
			if(bfsCycle(i) == true) {
				fl = true; 
				break; 
			}
		}
	}
	if(fl == true) cout << "cycle"; 
	else cout << "no cycle"; 
}
 
int vis[1000005], pathVis[1000005]; 
 
bool dfsCycleDG(int node) {
	vis[node] = 1; 
	pathVis[node] = 1; 
 
	for(auto it : adj[node]) {
		if(vis[it] == false) {
			if(dfsCycleDG(it) == true) {
				return true; 
			}
		}
		else if(vis[it] == 1 && pathVis[it] == 1) {
			return true; 
		}
	}
 
	pathVis[node] = 0;
	return false; 
}
void dfsCycleChecker() {
	bool fl = false; 
	for(int i = 1;i<=n;i++) {
		if(vis[i] == 0) {
			if(dfsCycleDG(i) == true) {
				fl = true; 
				break; 
			}
		}
	}
	if(fl == true) cout << "cycle"; 
	else cout << "no cycle"; 
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	int n;
	cin >> n; 
	int dp[n+1]; 
	memset(dp, -1, sizeof dp); 
 
 
	return 0;
 
}
 
 
