#include <stdio.h>
int main()
{
	/*freopen("in.txt", "r", stdin);*/
	int n,j;
	scanf("%d", &j);
	while(j--)
	{
		scanf("%d", &n);
		if(n<11)
		{
			printf("0 %d\n", n);
		}
		else printf("%d %d\n", (n-10), (n-(n-10)));
	}
	return 0;
}
