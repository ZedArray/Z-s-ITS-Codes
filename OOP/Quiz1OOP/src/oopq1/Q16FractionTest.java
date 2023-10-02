package oopq1;

import java.util.Scanner;

public class Q16FractionTest {
	static Scanner scanner = new Scanner(System.in);
	
	public static void start() {
		//Making the first fraction according to user input
		System.out.println("Insert Fraction 1\nf1 = Num1/Den1 \n");
		System.out.println("Num1: ");
		int num, den;
		num = scanner.nextInt();
		System.out.println("f1 = " + num + "/Den1");
		System.out.println("Den1: ");
		den = scanner.nextInt();
		Q16Fraction f1 = new Q16Fraction(num, den);
		System.out.println("f1 = "+ f1.toString());
		
		//Making the second fraction according to user input
		System.out.println("\nInsert Fraction 2\nf2 = Num2/Den2 \n");
		System.out.println("Num2: ");
		num = scanner.nextInt();
		System.out.println("f2 = " + num + "/Den2");
		System.out.println("Den2: ");
		den = scanner.nextInt();
		Q16Fraction f2 = new Q16Fraction(num, den);
		System.out.println("f2 = "+ f2.toString());
		
		//Asking the user to either get the sum or the product of the two fractions they just inputted
		System.out.println("\nf1 = " + f1.toString() + "\nf2 = " + f2.toString());
		System.out.println("1. Get Sum \n2. Get Product \n(Type number only 1/2)\n");
		int input;
		input = scanner.nextInt();		
		if (input == 1) {
			System.out.println(f1.toString() + " + " + f2.toString() + " = " + f2.getSum(f1));
		}
		else if (input == 2) {
			System.out.println(f1.toString() + " * " + f2.toString() + " = " + f2.getProduct(f1));
		}
	}
	
	public static void main(String[] args) {
		start();
	}
}
