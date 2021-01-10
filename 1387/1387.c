#include <stdio.h>
#include <string.h>
int main()
{
    unsigned short t,n;
    unsigned short case_no=0;
    char a[7];
    int ans=0;
    int donation =0;
    int s_ans[105];
    scanf("%hu", &t);
    while(t>0)
    {
        scanf("%hu", &n);
        case_no++;
        int i=0;
        int j=0;
        while(n>0)
        {
            scanf("%s", a);
            if (strcmp(a,"donate")==0)
                {
                    scanf("%d", &donation);
                    ans = ans+donation;
                }else
                {
                    s_ans[i]=ans;
                    i++;
                }
            n--;
        }
        printf("Case %hu:\n",case_no);
        while(i>0)
        {
            printf("%d\n", s_ans[j]);
            j++;
            i--;
        }
        ans=0;
        t--;
    }
    return 0;
}
