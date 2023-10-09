package Q13ComputerAccount;

public class Q13ComputerAccount {
	static String realName;
	static String userName;
	static String password;
	
	public static void realNameInsert(String input) {
		realName = input;
	}
	public static void userNameInsert(String input) {
		userName = input;
	}
	public static void passwordInsert(String input) {
		password = input;
	}
	public static void printRealName() {
		System.out.println("Real Name is: " + realName);
	}
	public static void printUserName() {
		System.out.println("Username is: " +userName);
	}
	public static void printPassword() {
		System.out.println("Password is: " +password);
	}
}
