#include <stdio.h>
int main()
{
	/*freopen("in.txt", "r", stdin);*/
	int t,a,b,ans,case_no = 0;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &a,&b);
		ans=a+b;
		case_no++;
		printf("Case %d: %d\n", case_no, ans);
	}
	return 0;
}
