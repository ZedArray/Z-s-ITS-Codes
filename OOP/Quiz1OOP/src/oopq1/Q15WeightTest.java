package oopq1;

import java.util.Scanner;

public class Q15WeightTest {
	static double weightInput;
	static int outputType, weightType;
	static Scanner scanner = new Scanner(System.in);
	static Q15Weight machine;
	
	//method for asking user input by asking the type of weight (pounds/kilograms) and the actual amount of weight
	public static void input() {
		System.out.println("Input Weight Type: \n1. Pounds \n2. Kilograms \n(Type only the number 1/2)");
		weightType = scanner.nextInt();
		System.out.println("Input Weight Amount: ");
		weightInput = scanner.nextDouble();
		
//		machine.wInput(weightInput, weightType);
		machine = new Q15Weight(weightInput,weightType);
		
	}
	
	
	//method for asking user which type of weight should it be outputted into
	public static void output() {
		System.out.println("Output Weight Type: \n1. Pounds \n2. Kilograms \n(Type only the number 1/2)");
		outputType = scanner.nextInt();
		if (outputType == 1) {
			machine.getPounds();
		}
		else if (outputType == 2) {
			machine.getKilograms();
		}
	}
	
	public static void main(String[] args) {
		input();
		output();
	}
}
