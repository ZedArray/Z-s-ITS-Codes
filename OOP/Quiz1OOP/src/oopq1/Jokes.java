package oopq1;

import java.util.Scanner;

public class Jokes {
	private static String jokeString;
	static Scanner scanner = new Scanner(System.in);
	
	//method for checking if the joke is funny or not (yes if string.length < 20, else no)
	public static void isFunny() {
		if(jokeString.length() < 20) {
			System.out.println("It's funny");
		}
		else {
			System.out.println("It's not funny");
		}
	}
	
	//method to print the first word by using the split function which splits a string to an array of words
	public static void firstWord() {
		String split[] = jokeString.split(" ");
		System.out.println(split[0]);
	}
	
	public static void main(String[] args) {
		jokeString = "Knock knock who's there?";
		isFunny();
		firstWord();
		jokeString = "Your life";
		isFunny();
		firstWord();
		
		//If user wants to test with other jokes
		System.out.println("Custom Joke? y/n");
		String input;
		input = scanner.nextLine();
		if (input.compareTo("y") == 0) {
			System.out.println("Insert Joke: ");
			jokeString = scanner.nextLine();
			while(true) {
				//keeps looping with command inputs. input with 0 to end loop
				System.out.println("Insert Command \n1. Funny Checker \n2. Print First Word \n0. Exit Code \n(Type only number 1/2/0)");
				int cmd;
				cmd = scanner.nextInt();
				if (cmd == 1) {
					isFunny();
				}
				else if (cmd == 2) {
					firstWord();
				}
				else if (cmd == 0) {
					break;
				}
			}
		}
		else {
			return;
		}
	}
}
