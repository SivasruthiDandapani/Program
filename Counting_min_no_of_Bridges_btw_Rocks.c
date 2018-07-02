/* QUESTION
zeitgeist_baba visits the land of rocks. There are a total of N rocks numbered
from 1 to N. Some pairs of rocks are connected to each other by Bidirectional
bridges running over water. zeitgeist_baba hates to cross these bridges as they
require a lot of efforts. He is standing at rock#1 and wants to reach the
rock#N. Find the minimum number of bridges that he shall have to cross, if
he takes the optimal route.

INPUT FORMAT :
First line contains T. T testcases follow. First line of each test case contains
two space-separated integers N, M. Each of the next M lines contains two
space-separated integers X and Y , denoting that there is a bridge between
RockX and RockY.

CONSTRAINTS : 
1 <= T <= 10
1 <= N <= 104
1 <= M <= 105
1 <= X, Y <= N

OUTPUT :
Print the answer to each test case in a new line

SAMPLE I/P :
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2

SAMPLE O/P :
2
2*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, j, t, n, m, *a, first, next, cnt = 0;
    scanf("%d",&t);
    for(j = 0; j < t; j++)
    {
        cnt = 0;
        scanf("%d %d",&n, &m); //Consider N as no. of rocks
        a = (int *)malloc((2*m) * sizeof(int));
        first = 1;  //Take 1 as first rock
        next = first + 1;
        for(i = 0; i < 2*m; i+=2)
        {
            scanf("%d %d", (a+i), (a+i+1));
        }
        //Get the next gratest rock
        L1 : for(i = 0; i < 2*m; i+=2)
        {
            if(*(a+i) == first && *(a+i+1) > next)
            {
                next = *(a+i+1);
            }
            if(*(a+i+1) == first && *(a+i) > next)
            {
                next = *(a+i);
            }
        }
        
        cnt++;
        //initialize that to first and iterate it until you reach the last rock
        if(next != n)
        {
            first = next;
            next = first + 1;
            goto L1;
        }
        else
        {
            printf("%d\n",cnt);
        }
    }
    return 0;
}

