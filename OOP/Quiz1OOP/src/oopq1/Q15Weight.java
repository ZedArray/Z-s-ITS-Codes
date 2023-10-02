package oopq1;

public class Q15Weight {
	static double weight = 0;
	static int wType = 0;
	//wType is type of weight
	//1. Pounds, 2. Kilograms
	
	//Realized after learning what constructors were on Q16 that my previous way of inputting needs only a little change for it to be an actual constructor so i made it
	//Constructor
	public Q15Weight(double input, int type) {
		wType = type;
		weight = input;
	}
	
	//my original way of inputting
//	public static void wInput(double input, int type) {
//		wType = type;
//		weight = input;
//	}
	
	//converts to pounds
	public static void getPounds() {
		if (wType == 1) {
			System.out.println(weight + " Pounds");
		}
		else if (wType == 2) {
			System.out.println(weight * 2.20462 + " Kilograms");
		}
	}
	
	//converts to kilograms
	public static void getKilograms() {
		if (wType == 1) {
			System.out.println(weight * 0.453592 + " Pounds");
		}
		else if (wType == 2) {
			System.out.println(weight + " Kilograms");
		}
	}
}
