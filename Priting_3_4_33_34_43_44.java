/*
Form a number system with only 3 and 4. Find the nth number of the number system.
Eg.) The numbers are: 3, 4, 33, 34, 43, 44, 333, 334, 343, 344, 433, 
434, 443, 444, 3333, 3334, 3343, 3344, 3433, 3434, 3443, 3444 ….
*/



import java.util.*;
import java.lang.*;

public class Number
{
    static int inc = 0, flag = 0;
    //Call the function recursively to get ech number. Traverse & see the result
	static void fun(int sum, int power, int n, int n1, int n2, int pos)
	{
		int r, pw;
		if(power == 0)
		{
		    inc++;
		    if(inc == pos)
		    {
			    System.out.print(sum+n + " ");
			    flag = 1;
			    System.exit(0);
		    }
		}
		else
		{
			pw = (int)Math.pow(10, (double)power);
			r = sum + (n * pw);
			fun(r, power-1, n1, n1, n2, pos);
			fun(r, power-1, n2, n1, n2, pos);
		}
	}
	public static void main(String a[])
	{
		int sum = 0, power = 0, n1, n2, Nth_num;
		Number num = new Number();  // Get the Nth position
		Scanner sc = new Scanner(System.in);
		Nth_num = sc.nextInt();
		n1 = 3;
		n2 = 4;
		while(flag == 0)
		{
			fun(sum, power, n1, n1, n2, Nth_num); //Print the possibilities for 3
			fun(sum, power, n2, n1, n2, Nth_num); //Print the possibilities for 4
			power++;
		}
		System.out.println();
	}
}