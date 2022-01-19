#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define N 100000
#define ll long long int
#define pb push_back


vector <bool> v;
vector <vector <int>> rev;
stack <int> sk;
int cnt=0;

void DFS1(int x, vector<int> g[]) {
    v[x]=true;
    for(auto i: g[x])
        if(v[i]==false)
            DFS1(i, g);
    sk.push(x);
}

void reverse(int n, vector <int> g[]) {
    int i;
    for(i=0; i<n; i++) {
        for(auto j: g[i]) {
            rev[j].pb(i);
        }
    }
}

void DFS2(int x) {
    v[x]=true;
    for(auto i: rev[x])
        if(v[i]==false)
            DFS2(i);
}

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        int n, temp;
        n=V;
        v.assign(V, false);
        rev.assign(V, vector <int> ());
        
        int i,x;
    
    //first dfs call
        for(i=0; i<n;i++)
            if(v[i]==false)
                DFS1(i, adj);
    
    //reverse directions of all edges
        reverse(n, adj);
        
        //clear visited array
        for(int i=0;i<n;++i)
    		v[i] = false;
    		
    	while(sk.empty()==false) {
            x=sk.top();
            sk.pop();
            if(v[x]==false) {
                DFS2(x);
                cnt++;
            }
        }
        temp=cnt;
        cnt=0;
        return temp;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
