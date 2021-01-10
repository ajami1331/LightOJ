/* lightOJ 1338 - Hidden Secret!  */
#include <cstdio>
#include <iostream>
#include <map>
#include <cctype>
using namespace std;
int main()
{
	#ifdef CLMAN
		freopen("in.txt", "r", stdin);
	#endif // CLMAN
	int n,csn;
	string s;
	map <char,int> m;
	bool fl;
	while(cin >> n)
	{
		csn=0;
		getline(cin,s);
		while(n--)
		{
			fl=true;
			m.clear();
			getline(cin,s);
			for(int i=0;i<s.size();i++)
			{
				if(s[i]!=' ')
				{
					m[tolower(s[i])]++;
				}
			}
			getline(cin,s);
			for(int i=0;i<s.size();i++)
			{
				if(s[i]!=' ')
				{
					if(m[tolower(s[i])]>0)
					{
						m[tolower(s[i])]--;
					}else
					{
						fl=false;
						break;
					}
				}
			}
			if(fl)
			{
				cout << "Case " << ++csn << ":" << " Yes\n";
			}else cout << "Case " << ++csn << ":" << " No\n";
		}
	}
	return 0;
}
