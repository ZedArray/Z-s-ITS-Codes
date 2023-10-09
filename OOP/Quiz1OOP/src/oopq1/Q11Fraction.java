package oopq1;

import java.util.Scanner;

public class Q11Fraction {
	//On the Behind the Scenes part, I make two methods. Sum and Prod. Sum will give a sum of the two fractions, Prod will give a product of the two fractions. Each methods prints out their result
	static Scanner scanner = new Scanner(System.in);
	public static int Sum(int e1, int d1, int e2, int d2) {
		int es, ds;
		es = (e1*d2) + (e2*d1);
		ds = d1*d2;
		
		System.out.println(es + "/" + ds);
		return 0;
	}
	public static int Prod(int e1, int d1, int e2, int d2) {
		int ep, dp;
		ep = e1*e2;
		dp = d1*d2;
		System.out.println(ep + "/" + dp);
		return 0;
	}

	public static void main(String[] args) {
		//Over here on the main method, I ask the user to input which operation they want. 1 for sum, 2 for product.
		
		int e1 = 0, d1 = 0, e2 = 0, d2 = 0;
		System.out.println("1. Sum\n2. Product");
		
		int input;
		input = scanner.nextInt();
		

		//After getting which operation the user wants, i ask the user to fill in the fraction by filling in the blanks (f1 = e1/d1, f2 = e2/d2).
		
		if(input == 1) {
			System.out.println("e1/d1 + e2/d2 =\n");
			System.out.println("Input e1:\n");
			e1 = scanner.nextInt();
			System.out.println(e1 + "/d1 + e2/d2 =\n");
			System.out.println("Input d1:\n");
			d1 = scanner.nextInt();
			System.out.println(e1 + "/" + d1 + " + e2/d2 =\n");
			System.out.println("Input e2:\n");
			e2 = scanner.nextInt();
			System.out.println(e1 + "/" + d1 + " + " + e2 + "/d2 =\n");
			System.out.println("Input d2:\n");
			d2 = scanner.nextInt();
			System.out.println(e1 + "/" + d1 + " + " + e2 + "/" + d2 +" =\n");
			Sum(e1, d1, e2, d2);
		}
		else if (input == 2) {
			System.out.println("e1/d1 * e2/d2\n");
			System.out.println("Input e1:\n");
			e1 = scanner.nextInt();
			System.out.println(e1 + "/d1 * e2/d2=\n");
			System.out.println("Input d1:\n");
			d1 = scanner.nextInt();
			System.out.println(e1 + "/" + d1 + " * e2/d2=\n");
			System.out.println("Input e2:\n");
			e2 = scanner.nextInt();
			System.out.println(e1 + "/" + d1 + " * " + e2 + "/d2=\n");
			System.out.println("Input d2:\n");
			d2 = scanner.nextInt();
			System.out.println(e1 + "/" + d1 + " * " + e2 + "/" + d2 +" =\n");
			Prod(e1, d1, e2, d2);
		}
	}
}