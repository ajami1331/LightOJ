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

#define pb				push_back
#define F				first
#define S				second
#define sf				scanf
#define pf				printf
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
typedef vector<int>		VI;
typedef vector<LL>		VL;
typedef vector<string>		VS;
typedef vector<char>		VC;
typedef vector<bool>		VB;
typedef vector<PII>		VII;
typedef map<string,int>		MSI;
typedef map<int,int>		MII;
typedef map<char,int>		MCI;
typedef map<int,string>		MIS;

template<typename T> T Abs(T x) { return x>0 ? x : -x ; }
template<typename T> T const& Max(T const& a, T const& b) { return a>b ? a : b ; }
template<typename T> T const& Min(T const& a, T const& b) { return a<b ? a : b ; }
template<typename T> inline T gcd(T a, T b) { return (b ? gcd(b,a%b) : a) ; }
template<typename T> inline T lcm(T a, T b) { return ( b / gcd(a,b) ) * a ; }
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

int T, n, k;
int ar[51],tr[51];
int dp[51][1001][21];
#define MOD 100000007

int calc(int i,int val,int lvl){
	if(i >= n ){
		if(val == k){
			return 1;
		}else{
			return 0;
		}
	}
	if(dp[i][val][lvl] != -1){
        return dp[i][val][lvl];
	}
	int ret1 = 0, ret2 = 0;
	if(val+ar[i] <= k && lvl < tr[i]){
        ret1 = calc(i,val+ar[i],lvl+1);
	}
	ret2 = calc(i+1,val,0);

	return dp[i][val][lvl] = ( (ret1) + (ret2) ) % MOD ;
}

int main(){
	#ifdef LU_SERIOUS
		freopen("in.txt","r",stdin);
	#endif // LU_SERIOUS
	si1(T);
	int ans;
	for(int csn=1; csn<=T; csn++){
		si2(n,k);
		for(int i=0; i<n; i++){
			si1(ar[i]);
		}
		for(int i=0; i<n; i++){
			si1(tr[i]);
		}
//        ms(dp,-1);
        for(int i=0; i<51; i++)
            for(int j=0; j<1001; j++)
                for(int k=0; k<21; k++)
                    dp[i][j][k] = -1;
		ans = calc(0,0,0);
		pf("Case %d: %d\n",csn,ans);
	}
	return 0;
}


