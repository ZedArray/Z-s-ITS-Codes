package oopq1;

import java.util.Scanner;

public class Q14StudentTest {
	static Q14Student machine = new Q14Student();
	static Scanner scanner = new Scanner(System.in);
	
	//This one's pretty similar to the previous one. It is just inputting datas and printing them
	
	public static void start() {
		String name, id, degree;
		System.out.println("Insert Name: ");
		name = scanner.nextLine();
		machine.nameInput(name);
		
		System.out.println("Insert ID: ");
		id = scanner.nextLine();
		machine.idInput(id);
		
		System.out.println("Insert Degree: ");
		degree = scanner.nextLine();
		machine.degreeInput(degree);
	}

	public static void main(String[] args) {
		start();
		machine.toString();
	}
}
