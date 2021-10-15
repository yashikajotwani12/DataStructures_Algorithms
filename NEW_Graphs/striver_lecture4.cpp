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

int col[1000005]; // -> make sure to make it -1 at every index
bool checkBipartite(int node, int color) {
	col[node] = color; 

	for(auto it : adj[node]) {
		// check for unvisited
		if(col[it] == -1) {
			if(checkBipartite(it, !color)) {
				return true; 
			}
		}
		// when it comes here it means the col[it] is marked 
		// as 1 or 0 which means it has been visited previously 
		// hence we check if the adjacent has same color or not 
		else if(col[it] != color) {
			return true; 
		}
	}
	return false; 
}

bool checkBipartiteBFS(int node, int color) {
	col[node] = color; 
	queue<pair<int,int>> q; 
	q.push({node, color}); 

	while(!q.empty()) {
		int node = q.front().first; 
		int color = q.front().second; 

		for(auto it : adj[node]) {
			if(vis[it] == -1) {
				q.push({it, !color}); 
				col[it] = !color; 
			}
			else if(col[it] == color) {
				return true; 
			}
		}
	}
	return false; 
}
void topoSortHelper(int node, stack<int> &st) {
	vis[node] = 1; 
	for(auto it : adj[node]) {
		if(!vis[it]) {
			topoSortHelper(it, st); 
		}
	}
	st.push(node); 
}

void topoSort() {
	stack<int> st; 
	for(int i = 1;i<=n;i++) {
		if(vis[i] == false) {
			topoSortHelper(i, st); 
		}
	}

	while(!st.empty()) {
		cout << st.top() << " "; 
		st.pop(); 
	}
}



void topoSort() {
	vector<int> indegree(n, 0); 

	// (1, 2)
	// adj[1].pb(2)
	for(int i = 0;i<n;i++) {
		for(auto it : adj[n]) {
			// i ---> it 
			indegree[it]++; 
		}
	}
	queue<int> q; 
	for(int i = 0;i<n;i++) {
		if(indegree[i] == 0) {
			q.push(i); 
		}
	}
	while(!q.empty()) {
		cout << q.front(); 
		int node = q.front(); 
		q.pop(); 

		for(auto it : adj[node]) {
			// node -> it 
			indegree[it]--; 
			if(indegree[it] == 0) q.push(it); 
		}
	}
}


class Solution {
private: 
    bool dfsCycle(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]) {
        vis[node] = 1; 
        pathVis[node] = 1; 
        
        for(auto it: adj[node]) {
            if(vis[it] == 0) {
                if(dfsCycle(it, vis, pathVis, adj) == true) return true; 
            }
            else if(pathVis[it] == 1) {
                return true; 
            }
        }
        pathVis[node] = 0; 
        return false; 
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0), pathVis(numCourses, 0); 
        
        vector<int> adj[numCourses]; 
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); 
        }
        
        for(int i = 0;i<numCourses;i++) {
            if(!vis[i]) {
                if(dfsCycle(i, vis, pathVis, adj)) {
                    return false;
                }
            }
        }
        return true; 
    }
};


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses]; 
        int n = numCourses; 
         vector<int> indegree(n, 0); 
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); 
            indegree[it[0]]++; 
        }
        queue<int> q; 
        for(int i = 0;i<numCourses;i++) {
            if(indegree[i] == 0) {
                q.push(i); 
            }
        }
        vector<int> ans; 
        int cnt = 0; 
        while(!q.empty()) {
            ans.push_back(q.front()); 
            cnt++; 
            int node = q.front(); 
            q.pop(); 

            for(auto it : adj[node]) {
                // node -> it 
                indegree[it]--; 
                if(indegree[it] == 0) q.push(it); 
            }
        }
        
        if(cnt != n) {
            vector<int> dummy; 
            return dummy; 
        }
        return ans;
    }
};

void bfszeroone(int source) {
	deque<pair<int,int>> dq;
	vector<int> dis(n, 0); 
	for(int i = 0;i<n;i++) {
		dis[i] = INT_MAX; 
	}
	dis[source] = 0; 
	dq.push_front({source, 0}); 

	while(!dq.empty()) {
		int node = dq.front().first; 
		int dist = dq.front().second; 
		dq.pop_front(); 

		for(auto it : adj[node]) {
			int adjNode = it.first;
			int wt = it.second; 
			if(dist + wt < dis[adjNode]) {
				dis[adjNode] = dist + wt; 
				if(wt == 1) {
					dq.push_back({adjNode, dist + wt}); 
				}
				else 
					dq.push_front({adjNode, dist + wt}); 
			}
		}
	}
	for(int i = 0;i<n;i++) {
		cout << dist[i] << " "; 
	}
}


void djikstra(int source) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
	vector<int> dis(n, 0); 
	for(int i = 0;i<n;i++) {
		dis[i] = INT_MAX; 
	}
	dis[source] = 0; 
	pq.push({0, source}); 

	while(!dq.empty()) {
		int node = dq.top().first; 
		int dist = dq.top().second; 
		dq.pop();

		for(auto it : adj[node]) {
			int adjNode = it.first;
			int wt = it.second; 
			if(dist + wt < dis[adjNode]) {
				dis[adjNode] = dist + wt; 
				pq.push({dist + wt, adjNode}); 
			}
		}
	}
	for(int i = 0;i<n;i++) {
		cout << dist[i] << " "; 
	}
}



void djikstra(int source) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
	vector<int> dis(n+1, 0); 
	for(int i = 1;i<=n;i++) {
		dis[i] = INT_MAX; 
	}
	dis[source] = 0; 
	pq.push({0, source}); 
	vector<int> par(n+1, 0); 
	par[1] = 1;

	while(!dq.empty()) {
		int node = dq.top().first; 
		int dist = dq.top().second; 
		dq.pop();

		for(auto it : adj[node]) {
			int adjNode = it.first;
			int wt = it.second; 
			if(dist + wt < dis[adjNode]) {
				dis[adjNode] = dist + wt; 
				par[adjNode] = node; 
				pq.push({dist + wt, adjNode}); 
			}
		}
	}
	for(int i = 0;i<n;i++) {
		cout << dist[i] << " "; 
	}

	int x = n; 
	cout << x << " "; 
	while(parent[x] != 1) {
		x = parent[x]; 
		cout << x << " "; 
	}
}

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         long long mod = (1e9 + 7); 
         vector<long long> ways(n, 0); 
         long long maxi = 1e18; 
         vector<long long> dist(n, maxi); 
        
         dist[0] =0; 
         ways[0] =1;
         
        vector<pair<long long,long long>> adj[n]; 
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]}); 
            adj[it[1]].push_back({it[0], it[2]}); 
        }
        
         priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0, 0}); 
        while(!pq.empty()) {
            long long node = pq.top().second;
            long long dis = pq.top().first; 
            pq.pop(); 
            
            for(auto it : adj[node]) {
                long long wt = it.second; 
                long long adjNode = it.first; 
                if(wt + dis < dist[adjNode]) {
                    dist[adjNode] = wt + dis; 
                    ways[adjNode] = ways[node]; 
                    pq.push({dist[adjNode], adjNode}); 
                }
                else if(wt + dis == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod; 
                }
            }
        }
        return ways[n-1]; 
    }
};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; 
        int n = maze.size();
        int m = maze[0].size(); 
        vector<int> dist(n * m + 1, 0); 
        for(int i = 0;i<= n*m;i++) {
            dist[i] = INT_MAX; 
        }
        dist[start[0] * m + start[1]] = 0; 
        pq.push({0, {start[0], start[1]}}); 
        int dx[] = {-1, +1, 0, 0};
        int dy[] = {0, 0, +1, -1};
        while(!pq.empty()) {
            int dis = pq.top().first;
            int x = pq.top().second.first; 
            int y = pq.top().second.second; 
            pq.pop(); 
            
            for(int ind = 0;ind < 4;ind++) {
                int newx = x;
                int newy = y; 
                int cnt = 0; 
                while(newx >= 0 && newy >= 0 && newx < n && newy < m && maze[newx][newy] == 0) {
                    newx += dx[ind]; 
                    newy += dy[ind]; 
                    cnt++; 
                }
                newx -= dx[ind]; 
                newy -= dy[ind]; 
                cnt--; 
                
                if(dis + cnt < dist[newx * m + newy]) {
                    dist[newx * m + newy] = dis + cnt; 
                    pq.push({dis + cnt,{newx,  newy}}); 
                }
            }
        }
        if(dist[destination[0] * m + destination[1]] == INT_MAX)  {
            return -1; 
        }
        return dist[destination[0] * m + destination[1]]; 
    }
};
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

// https://i...content-available-to-author-only...e.com/rJrmAZ


















