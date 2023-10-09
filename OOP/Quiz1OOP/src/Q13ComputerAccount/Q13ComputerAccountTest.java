package Q13ComputerAccount;

import Q13ComputerAccount.Q13ComputerAccount;
import java.util.Scanner;

public class Q13ComputerAccountTest {
	static Q13ComputerAccount machine;
	static Scanner scanner = new Scanner(System.in);
	
	public static void start() {
		System.out.println("Insert Real Name: ");
		String realName;
		realName = scanner.nextLine();
		machine.realNameInsert(realName);
		
		System.out.println("\nInsert User Name: ");
		String userName;
		userName = scanner.nextLine();
		machine.userNameInsert(userName);
		
		System.out.println("\nInsert Password: ");
		String password;
		password = scanner.nextLine();
		machine.passwordInsert(password);
	}
	
	public static void changePassword() {
		System.out.println("Insert New Password: ");
		String newPassword;
		newPassword = scanner.next();
		machine.passwordInsert(newPassword);
	}
	
	public static void program() {
		System.out.println("\nWhat is thy bidding my master");
		while(true) {
			System.out.println("\n1. Print Real Name \n2. Print User Name \n3. Print Password \n4. Change Password \n0. Exit \n(Type only the number)");
			int input;
			input = scanner.nextInt();
			if (input == 0) {
				return;
			}
			else if (input == 1) {
				machine.printRealName();
			}
			else if (input == 2) {
				machine.printUserName();
			}
			else if (input == 3) {
				machine.printPassword();
			}
			else if (input == 4) {
				changePassword();
			}
			else {
				System.out.println("Unexpected Input\n");
			}
		
//			switch (input) {
//			case 0:{
//				return;
//			}
//			case 1: {
//				machine.printRealName();
//				break;
//			}
//			case 2: {
//				machine.printUserName();
//				break;
//			}
//			case 3: {
//				machine.printPassword();
//				break;
//			}
//			case 4: {
//				System.out.println("Insert New Password: ");
//				String newPassword;
//				newPassword = scanner.nextLine();
//				machine.passwordInsert(newPassword);
//				break;
//			}
//			default:
//				throw new IllegalArgumentException("Unexpected value: " + input);
//			}
		}
	}
	
	public static void main(String[] args) {
		start();
		program();
	}
}
