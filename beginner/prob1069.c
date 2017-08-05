#include <stdio.h>

int main()
{
    short _cases,your_pos,lift_pos;
    short case_no = 0;
    short ans = 0;
    short pos_diff = 0;
    scanf("%hd", &_cases);
    while(_cases>0)
    {
        ans = 0;
        scanf("%hd%hd", &your_pos, &lift_pos);
        pos_diff = lift_pos - your_pos;
        if(pos_diff<0)
        {
            pos_diff = -pos_diff;
        }
        ans = (pos_diff * 4) + (your_pos * 4) + 3 + 3 + 3 + 5 + 5;
        case_no++;
        printf("Case %hd: %hd\n", case_no, ans);
        _cases--;
    }
    return 0;
}
