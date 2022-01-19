/* 
    problem title : Strongly connected component (Tarjans's Algo) 
    problem link  : https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1# 
*/



#include<bits/stdc++.h>
using namespace std;

#define N 100000
#define ll long long int
#define pb push_back

vector <int> disc, low;
vector <bool> presentInStack;
stack <int> sk;
int timer=0;

int dfs(int u,  vector<int> g[], vector<vector<int>> & res) {
    
    disc[u]=timer;
    low[u]=timer;
    timer++;
    sk.push(u);
    presentInStack[u]=true;
    
    
    for(auto v: g[u]) {
        //if v is not already visited, visit it
        if(disc[v]==-1) {
            dfs(v, g, res);
            low[u]=min(low[u], low[v]);  //tree edge formula
        }
        //if v is present in stack, then uv is a back edge
        else if(presentInStack[v]) {
            low[u]=min(low[u], disc[v]); //back edge formula
        }
        else {
            //else uv is a cross edge, so do nothing
        }
    }
    
    /* printing SCCs, 
    if low[u]=disc[u], then the node is the
    head node of SCC */
    
    if(low[u]==disc[u]) {
        
        //pop and print until u see head node
        vector <int> temp;
        while(sk.top()!=u) {
            temp.pb(sk.top());
            presentInStack[sk.top()]=false;
            sk.pop();
        }
        
        //pop the head node too
        
        temp.pb(sk.top());
        presentInStack[sk.top()]=false;
        sk.pop();
        res.pb(temp);
    }
    
}


class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    
    vector<vector<int>> tarjans(int n, vector<int> g[])
    {
        //code here
        int i, j;
        disc.assign(n, -1);
        low.assign(n, -1);
        presentInStack.assign(n, false);
        
        vector<vector<int>> res;
        
        while(sk.empty()==false) {
            sk.pop();
        }
        
        for(i=0; i<n; i++)
            if(disc[i]==-1)
                dfs(i, g, res);
                
        timer=0;
        
        for(i=0; i<res.size(); i++) {
                sort(res[i].begin(), res[i].end());
        }
        if(res.size()>1)
            sort( res.begin(), res.end() );
        
        disc.clear();
        low.clear();
        presentInStack.clear();
        
        return res;
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
  
  
