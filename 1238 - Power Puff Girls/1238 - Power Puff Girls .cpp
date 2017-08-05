//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <cstdlib>
//#include <cassert>
//#include <cctype>
//#include <ctime>
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <map>
//#include <queue>
//#include <deque>
//#include <stack>
//#include <list>
//#include <set>
//#include <bitset>
//#include <utility>
//#include <unordered_set>
//#include <unordered_map>
//#include <iterator>
//#include <sstream>
//#include <fstream>
//#include <limits>
//#include <new>
//#include <memory>
#include <bits/stdc++.h>

using namespace std;

#define pb					push_back
#define F					first
#define S					second
#define sf					scanf
#define pf					printf
#define si1(x)				scanf("%d",&x)
#define si2(x,y)			scanf("%d %d",&x,&y)
#define si3(x,y,z)			scanf("%d %d %d",&x,&y,&z)
#define sd1(x)				scanf("%lf",&x)
#define sd2(x,y)			scanf("%lf %lf",&x,&y)
#define sd3(x,y,z)			scanf("%lf %lf %lf",&x,&y,&z)
#define sl1(x)				scanf("%lld",&x)
#define sl2(x,y)			scanf("%lld %lld",&x,&y)
#define sl3(x,y,z)			scanf("%lld %lld %lld",&x,&y,&z)
#define sz(x)				(int)x.size()
#define all(x)				(x.begin(), x.end())
#define ms(x,a)				memset(x,a,sizeof(x))
#define rep(i,a,b)			for(int i=(a); i<(b); i++)
#define repC(i,x)			for(int i=0; i<(sz(x)); i++)
#define repIT(it,x)			for(__typeof((x).begin()) it=(x).begin(); it!=x.end(); it++)

typedef long long int		LL;
typedef pair<int,int>		PII;
typedef vector<int>			VI;
typedef vector<LL>			VL;
typedef vector<string>		VS;
typedef vector<char>		VC;
typedef vector<bool>		VB;
typedef vector<PII>			VII;
typedef map<string,int>		MSI;
typedef map<int,int>		MII;
typedef map<char,int>		MCI;
typedef map<int,string>		MIS;

template<typename T> T Abs(T x) { return x>0 ? x : -x ; }
template<typename T> T const& Max(T const& a, T const& b) { return a>b ? a : b ; }
template<typename T> T const& Min(T const& a, T const& b) { return a<b ? a : b ; }
template<typename T> inline T gcd(T a, T b) { return (b ? gcd(b,a%b) : a) ; }
template<typename T> T sqaa(T a){ return a*a ; }
template<typename T> inline T powa(T x,T p){
	if(!p)
		return 1;
	else
		if(p&1)
			return x*powa(x,p-1);
		else{
			T ret = powa(x,p>>1);
			return ret*ret;
		}
}

int destx, desty;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int bfs(PII cor,char ma[][21],int m, int n);

int main(){
	#ifdef LU_SERIOUS
		freopen("in.txt","r",stdin);
	#endif // LU_SERIOUS
	int t, m, n, h1, h2, h3;
	char mapp[21][21], mapp1[21][21], mapp2[21][21];
	vector<pair<int, int> > vp;
	si1(t);
	for(int csn=1; csn<=t; csn++){
		si2(m,n);
		vp.clear();
		for(int i=0; i<m; i++){
			sf("%s",mapp[i]);
			for(int j=0; j<n; j++){
				mapp1[i][j] = mapp[i][j];
				mapp2[i][j] = mapp[i][j];
				if(mapp[i][j] == 'a'){
					vp.pb(PII(i,j));
				}
				if(mapp[i][j] == 'b'){
					vp.pb(PII(i,j));
				}
				if(mapp[i][j] == 'c'){
						vp.pb(PII(i,j));
				}
				if(mapp[i][j] == 'h'){
						destx = i;
						desty = j;
				}
			}
		}
//		cout << destx << " " << desty << "\n";
		h1 = bfs(vp[0], mapp,m,n);
		h2 = bfs(vp[1], mapp1,m,n);
		h3 = bfs(vp[2], mapp2,m,n);


		pf("Case %d: %d\n",csn,Max(h1,Max(h2,h3)));
	}
	return 0;
}

int bfs(PII cor,char ma[][21],int m,int n){
	int lvl[21][21] = {0};
	bool vis[21][21] = {0};
	vis[cor.F][cor.S] = true;

	int xx, yy;

	queue<PII> q;

	q.push(cor);

	while(!q.empty()){
		PII top = q.front();
		q.pop();

		int x = top.F;
		int y = top.S;
		for(int i=0; i<4; i++){
			int tx = x+dx[i];
			int ty = y+dy[i];
			if(tx >= 0 && tx <m && ty >=0 && ty <n){
				if(ma[tx][ty] == 'h'){
					if(!lvl[tx][ty])
						lvl[tx][ty] = lvl[x][y] + 1;
					xx = tx;
					yy = ty;
					break;
				}
				if(ma[tx][ty] != '#' && ma[tx][ty] != 'm'){
					lvl[tx][ty] = lvl[x][y] + 1;
					ma[tx][ty] = '#';
					q.push(PII(tx,ty));
				}
			}
		}
	}
//	cout << cor.F << " " << cor.S << "\n";
//	cout << xx << " " << yy << "\n";
//	cout << "lvl: " << lvl[xx][yy] << "\n";
//	if(cor.F == 3 && cor.S == 2)
//	for(int i=0; i<m; i++){
//		for(int j=0; j<n; j++){
//			cout << lvl[i][j] << " ";
//		}
//		cout << "\n";
//	}
	return lvl[xx][yy];
}
