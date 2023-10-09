package Q12Time;

import java.util.Scanner;

public class Q12Time {
	public static void angleFinder(int hour, int minute) {
		int degH = 0, degM = 0, result = 0;
		degH = (hour * 30) + (minute / 2);
		degM = minute * 6;
//		System.out.println(degH + " " + degM);
		if (degH > degM) {
			result = degH - degM;
		}
		else if (degM > degH){
			result = 360 - (degM - degH);
		}
//		result = degM > degH ? degM - degH : degH - degM;
		while(result > 360) {
			result -= 360;
		}
		System.out.println(result);
		//System.out.println(degM > degH ? 360 - (degM - degH) : 360 - (degH - degM));
	}
	public static void main(String[] args) {
		System.out.println("hello");
		Scanner scanner = new Scanner(System.in);
		int hour, minute;
		System.out.println("Input Hour");
		hour = scanner.nextInt();
		
		System.out.println("Input Minute");
		minute = scanner.nextInt();
		
		if (minute > 9) {
			System.out.println(hour + ":" + minute);
		}
		else {
			System.out.println(hour + ":0" + minute);
		}
		//System.out.println((hour * 30) + (minute%2 == 0 ? minute/2 : (minute/2)+1));
		angleFinder(hour, minute);
	}
}
