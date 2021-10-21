#include <stdio.h>
#include <stdio.h>

main()

{
    int j, c;
    c = 0;

    static char num[2][9] = {"17208980", "28219198"};

    for (j = 7; j >= 0; j--)

    {
        c = num[0][j] + num[1][j] - 2 * '0';

        // printf("%d\n",c);

        num[0][j] = c % 10 + '0';

        c = c / 10;
    }

    printf("%s\n", num[0]);
}