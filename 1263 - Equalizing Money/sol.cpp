#include <bits/stdc++.h>
using namespace std;
int n, m, t, cs(0), mn[1005], par[1005], taka[1005], cnt[1005];

void init(){
	for(int i=0; i<1005; i++){
		par[i] =i;
		taka[i] = 0;
		cnt[i] = 1;
	}
}

int bap(int a){
	return a == par[a] ? a : par[a] = bap(par[a]);
}

void uni(int u,int  v){
	if((u = bap(u)) != (v = bap(v))){
		par[v] = par[u];
		cnt[u] += cnt[v];
	}
}

void check(int sum){
	for(int i=1; i<=n; i++){
		taka[bap(i)] += mn[i];
	}
	bool fl(true);
	for(int i=1; i<=n; i++){
		int u = bap(i);
		if(taka[u] / cnt[u] != sum || taka[u] % sum != 0){
			fl = false;
		}
	}
	if(fl){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
}

int main(){
	cin >> t;
	while(t-- && cin >> n >> m){
		int sum = 0;
		init();
		for(int i=1; i<=n; i++) cin >> mn[i], sum += mn[i];
		for(int i=0; i<m; i++){
			int u, v; cin >> u >> v;
			uni(u,v);
		}
		cout << "Case " << ++cs << ": ";
		sum /= n;
		check(sum);
	}
    return 0;
}

