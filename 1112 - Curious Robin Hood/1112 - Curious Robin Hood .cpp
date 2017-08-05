#include <bits/stdc++.h>

using namespace std;

#define pb                              push_back
#define F                               first
#define S                               second
#define EPS                             1e-9
#define sf                              scanf
#define pf                              printf
#define si1(x)                          scanf("%d",&x)
#define si2(x,y)                        scanf("%d %d",&x,&y)
#define si3(x,y,z)                      scanf("%d %d %d",&x,&y,&z)
#define sd1(x)                          scanf("%lf",&x)
#define sd2(x,y)                        scanf("%lf %lf",&x,&y)
#define sd3(x,y,z)                      scanf("%lf %lf %lf",&x,&y,&z)
#define sl1(x)                          scanf("%lld",&x)
#define sl2(x,y)                        scanf("%lld %lld",&x,&y)
#define sl3(x,y,z)                      scanf("%lld %lld %lld",&x,&y,&z)
#define sz(x)                           (int)(x).size()
#define all(x)                          (x).begin(), (x).end()
#define rall(x)                         (x).rbegin(), (x).rend()
#define ms(x,a)                         memset(x,a,sizeof(x))
#define REP(i,a,b)                      for(int i=(a); i<(b); i++)
#define REPC(i,x)                       for(int i=0; i<(sz(x)); i++)
#define REPIT(it,x)                     for(__typeof((x).begin()) it=(x).begin(); it!=(x).end(); it++)

typedef long long int                   LL;
typedef pair<int,int>                   PII;
typedef vector<int>                     VI;
typedef vector<LL>                      VL;
typedef vector<string>                  VS;
typedef vector<char>                    VC;
typedef vector<bool>                    VB;
typedef vector<PII>                     VII;
typedef map<string,int>                 MSI;
typedef map<int,int>                    MII;
typedef map<char,int>                   MCI;
typedef map<int,string>                 MIS;

template<typename T> T Abs(T x) { return x>0 ? x : -x ; }
template<typename T> T const& Max(T const& a, T const& b) { return a>b ? a : b ; }
template<typename T> T const& Min(T const& a, T const& b) { return a<b ? a : b ; }
template<typename T> inline T gcd(T a, T b) { return (b ? gcd(b,a%b) : a) ; }
template<typename T> T sqaa(T a){ return a*a ; }

const int MAXN = (1e5) + 5;
int tree[MAXN], ar[MAXN];

void update(int idx,int x,int n){
	for(; idx <= n; idx += idx&-idx) tree[idx] += x;
}

int query(int idx){
	int sum = 0;
	for(; idx > 0; idx -= idx&-idx) sum += tree[idx];
	return sum;
}

int main(){
#ifdef LU_SERIOUS
    freopen("in.txt","r",stdin);
#endif // LU_SERIOUS
	int n, q, T, h, x, y, cs = 0;
	si1(T);
	while(T-- && ~si2(n,q)){
		ms(tree,0);
		REP(i,1,n+1){
			si1(ar[i]);
			update(i,ar[i],n);
		}
		cout << "Case " << ++cs << ":\n";
		REP(i,0,q){
			si2(h,x);
			if(h == 1){
				update(x+1,-ar[x+1],n);
				cout << ar[x+1] << "\n";
				ar[x+1] = 0;
			}else if(h == 2){
				si1(y);
				update(x+1,y,n);
				ar[x+1] += y;
			}else{
				si1(y);
				cout << query(y+1) - query(x) << "\n";
			}
		}
	}
	return 0;
}

