/* lightOJ 1249 Chocolate Thief */
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif // CLMAN
	int tc,n,csn;
	while(cin >> tc)
	{
		csn=0;
		while(tc--)
		{
			int x,y,z,ar[101];
			vector<string> vs;
			string st;
			vs.clear();
			string thief,vict;
			bool sol=false;

			cin >> n;
			int mx=-1000001,mn=1000001;
			for(int i=0;i<n;i++)
			{
				cin >> st >> x >> y >> z;
				ar[i]=x*y*z;
				vs.push_back(st);
				if(mn>ar[i])
				{
					mn=ar[i];
				}
				if(mx<ar[i])
				{
					mx=ar[i];
				}
			}
			if(mx!=mn)
			{
				for(int i=0;i<n;i++)
				{
					if(ar[i]==mx)
					{
						thief=vs[i];
						sol=true;
					}
					if(ar[i]==mn)
					{
						vict=vs[i];
						sol=true;
					}
				}
			}
			if(sol)
			{
				cout << "Case " << ++csn << ": " << thief << " took chocolate from " << vict << "\n";
			}else cout << "Case " << ++csn << ": no thief\n";
		}
	}
	return 0;
}
