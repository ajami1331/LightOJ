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
#define EPS					1e-9
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
#define sz(x)				(int)(x).size()
#define all(x)				(x).begin(), (x).end()
#define ms(x,a)				memset(x,a,sizeof(x))
#define REP(i,a,b)			for(int i=(a); i<(b); i++)
#define REPC(i,x)			for(int i=0; i<(sz(x)); i++)
#define REPIT(it,x)			for(__typeof((x).begin()) it=(x).begin(); it!=(x).end(); it++)

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
const int MOD = 1e8 + 7;
int dp[101][10001];
int coins[101];
int n, k;

int calc(){
	REP(i,0,n+1){
		dp[i][0] = 1;
	}
	REP(i,0,k+1){
		dp[0][i] = 0;
	}
    REP(i,1,n+1){
		REP(j,1,k+1){
			if(coins[i] <= j){
				dp[i][j] = ( dp[i-1][j] + dp[i][j-coins[i]] ) % MOD;
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
    }
    return dp[n][k] % MOD;
}

int main(){
	#ifdef LU_SERIOUS
		freopen("in.txt","r",stdin);
	#endif // LU_SERIOUS
	int T;
	si1(T);
	REP(cs,1,T+1){
		si2(n,k);
		REP(i,1,n+1){
			si1(coins[i]);
		}
		pf("Case %d: %d\n",cs,calc());
	}
	return 0;
}

