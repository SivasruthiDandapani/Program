/*  QUESTION :
Battlegrounds

Battlegrounds is a game which has a map denoted by an NxM matrix. The map can have open areas (where players can move) denoted by 0s, 1s where there are people or closed areas (where players can’t move) denoted by Xs. Each player should be able to move around the map and should be able to reach every other player’s location. Consider you are the game’s developer. Given the map you need to find if they all can reach each other. Each player can move up, down, left and right on the map.

Input: First line of the input contains 2 space separated integers N and M.

         Next N lines contain N values that can be either X or 0 denoting the map matrix.


Output: Single character Y if all players can reach each other with given moves or N if they can’t.
 

Sample Input 1

4 4
X01X
10X0
XX00
0X0X

Sample Ouput 1

Y
 

Sample Input 2

4 4
X00X
10X0
XX00
0X1X

 
Sample Ouput 2

N
*/


#include<stdio.h>
#include<stdlib.h>


int r, c;
char ch;


//Traverse the matrix using backtracking and fill the dummy matrix with 1 if reached
void Path(char a[r][c],int x, int y, int sol[r][c])
{
    if(y != 0 && a[x][y-1] != 'X' && sol[x][y-1] != 1)
    {
        sol[x][y-1] = 1;
        Path(a,x, y-1, sol);
    }
    if(y != r-1 && a[x][y+1] != 'X' && sol[x][y+1] != 1)
    {
        sol[x][y+1] = 1;
        Path(a, x, y+1, sol);
    }
    if(x != 0 && a[x-1][y] != 'X' && sol[x-1][y] != 1)
    {
        sol[x-1][y] = 1;
        Path(a, x-1, y, sol);
    }
    if(x != c-1 && a[x+1][y] != 'X' && sol[x+1][y] != 1)
    {
        sol[x+1][y] = 1;
        Path(a, x+1, y, sol);
    }
    
}

int main() {
    int i, j, flag = 0, brk = 0;
    scanf("%d%d", &r, &c);
    char a[r][c];
    int sol[r][c]; //Create a dummy matrix to track the path
    scanf("%c",&ch);
    for(i = 0; i < r; i++)
    {
        
        for(j = 0; j < c; j++)
        {
            sol[i][j] = 0;
            scanf("%c", &a[i][j]);
            
        }
        scanf("%c",&ch);
    }
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(a[i][j] == '1')
            {
                sol[i][j] = 1;
                Path(a, i, j, sol);  //Call the function that stores the path from this position
                brk = 1;
                break;
            }
        }
        if(brk == 1)
            break;
    }
    
    brk = 0;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(a[i][j] == '1' && sol[i][j] != 1) //Check the original array with the dummy array for all positions
            {
                flag = 0;
                printf("N");
                brk = 1;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        if(brk == 1)
            break;
    }
    if(flag == 1)
        printf("Y");
}
