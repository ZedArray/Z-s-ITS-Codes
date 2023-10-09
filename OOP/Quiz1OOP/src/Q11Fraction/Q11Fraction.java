package Q11Fraction;

import java.util.Scanner;

public class Q11Fraction {
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
//		Object e1;
//		Integer e2 = 0;
		int e1 = 0, d1 = 0, e2 = 0, d2 = 0;
		int es = 0, ds = 0, ep = 0, dp = 0;
		System.out.println("1. Sum\n2. Product");
		
		Scanner scanner = new Scanner(System.in);
		
		int input;
		input = scanner.nextInt();
		
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
