package oopq1;

public class Q14Student {
	//still no proper constructor
	
	//stores data
	static String name;
	static String degree;
	static String id;
	
	//inputs name
	public static void nameInput(String input) {
		name = input;
	}
	
	//inputs degree
	public static void degreeInput(String input) {
		degree = input;
	}
	
	//inputs ID
	public static void idInput(String input) {
		id = input;
	}
	
	//prints out the data with the preset format of [name, id, degree]
	public String toString() {
		System.out.println("[" + name + ", ID: " + id + ", " + degree + "]\n");
		return null;
	}
}
