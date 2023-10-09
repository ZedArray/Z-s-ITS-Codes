package oopq1;

import java.util.Scanner;

public class Q12Time {
	
	//I make a method called the angle finder to find the final result of the gap between each hand
	public static void angleFinder(int hour, int minute) {
		int degH = 0, degM = 0, result = 0;
		//degH being the degree of the Hour hand. The default ratio is 30 degrees every hour. But the minutes still affect the hour hand so I've added extra degrees with the ratio of 1 degree every 2 minutes
		degH = (hour * 30) + (minute / 2);
		//Minute hand degree with the ratio of 6 degrees every minute
		degM = minute * 6;
		
		//this if and else if statement i made after a bit of tinkering with how the degree conversion should be
		if (degH > degM) {
			result = degH - degM;
		}
		else if (degM > degH){
			result = 360 - (degM - degH);
		}
		
		//this while loop to decrease it by 360 degrees in case it goes over 360 degrees
		while(result > 360) {
			result -= 360;
		}
		System.out.println(result);
	}
	public static void main(String[] args) {
		System.out.println("hello");
		Scanner scanner = new Scanner(System.in);
		int hour, minute;
		
		//hour input
		System.out.println("Input Hour");
		hour = scanner.nextInt();
		
		//minute input
		System.out.println("Input Minute");
		minute = scanner.nextInt();
		
		//printing out the time inputted
		if (minute > 9) {
			System.out.println(hour + ":" + minute);
		}
		else {
			System.out.println(hour + ":0" + minute);
		}
		
		//running the angle finder method
		angleFinder(hour, minute);
	}
}
