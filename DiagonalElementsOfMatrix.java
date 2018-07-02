/*

Printing diagonal of a matrix

I/P
    1 2 3 4
    5 6 7 8
    9 10 11 12
    
O/P
    1
    2 5
    3 6 9
    4 7 10
    8 11
    12


*/



import java.util.*;

public class MyClass {
    public static void main(String args[]) {
        int row, col, r, c, i, j;
        Scanner sc = new Scanner(System.in);
        row = sc.nextInt();
        col = sc.nextInt();
        int[][] matrix = new int[row][col];
        for(i = 0; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                matrix[i][j] = sc.nextInt();
            }
        }
        
        //Printing upto first half
        for(j = 0; j < col; j++)
        {
            for(r = 0, c = j; (r!=row-1 && c!=0); r++, c--)
            {
                System.out.print(matrix[r][c] + " ");
            }
            System.out.print(matrix[r][c] + "\n");
        }
        
        //Print the second half
        for(i = 1; i < row; i++)
        {
            for(r = i, c = col-1; (r!=row-1 && c!=0); r++, c--)
            {
                System.out.print(matrix[r][c] + " ");
            }
            System.out.print(matrix[r][c] + "\n");
        }
        
    }
}
