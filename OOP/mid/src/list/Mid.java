package list;

public class Mid extends List {

    // 8
    static List negateAll(List a) {
    	// Your code is in here
    	a.head *= -1;
    	if(!a.empty()) {
    		negateAll(a.tail());    		
    	}
    	return a;
    }

    // 9
    static int counter = 0;
    static int find(int x, List a) {
    	// Your code is in here
    	int index = 0;
    	if (a.empty()) {
    		return -1;
    	}
    	else if (a.head != x) {
    		counter++;
    		index = find(x, a.tail());
    	}
    	else if (a.head == x) {
    		index = counter;
    		counter = 0;
    		return index;
    	}
    	return index;
    }

    // 10
    static boolean allPositive(List a) {
    	// Your code is in here
    	boolean defState = true;
    	if (a.empty()) {
    		return true;
    	}
    	if(a.head() >= 0) {
    		defState = allPositive(a.tail());
    	}
    	else if (a.head() < 0) {
    		return false;
    	}
    	return defState;
    }

    // 11
	static List positives(List a){
		List temp = new List();
		return positives(a, temp);
	}
    static List positives(List a, List temp) {
    	// Your code is in here
    	if (a.empty()) return temp;
    	else if (a.head() >= 0) {
    		temp = ListOps.addtoendr(temp, a.head());
    	}
		temp = positives(a.tail(), temp);
    	return temp;
    }

    // 12
    static boolean sorted(List a) {
    	// Your code is in here
		boolean defState = false;
    	if (a.tail.empty()) return true;
		else if (a.head() <= a.tail.head()){
			// System.out.println("\n" + a.head() + " " + a.tail.head());
			defState = sorted(a.tail());
		}
    	return defState;
    }
    
    // 13
	static List merge(List a, List b){
		List tempList = new List();
		return merge(a, b, tempList);
	}
    static List merge(List a, List b, List temp) {
    	// Your code is in here
		// ListOps.printList(temp);
		// System.out.println("\n");
		if (a.empty() && b.empty()) return temp;
		else if (a.empty()){
			temp = ListOps.addtoendr(temp, b.head());
			temp = merge(a, b.tail(), temp);
		}
		else if (b.empty()){
			temp = ListOps.addtoendr(temp, a.head());
			temp = merge(a.tail(), b.tail(), temp);
		}
		else if (a.head() >= b.head()){
			temp = ListOps.addtoendr(temp, b.head());
			temp = merge(a, b.tail(), temp);
		}
		else if (a.head < b.head()){
			temp = ListOps.addtoendr(temp, a.head());
			temp = merge(a.tail(), b, temp);
		}
		// ListOps.printList(temp);
		// System.out.println("\n");
		return temp;
    }

    // 14
	static List removeDuplicate(List a){
		return removeDuplicate(a.tail(), new List(a.head(), List.nil()), a.head());
	}
    static List removeDuplicate(List a, List temp, int prev) {
    	// Your code is in here
		// System.out.println("\nOriginal List");
		// ListOps.printList(a);
		// System.out.println("\nto be List");
		// ListOps.printList(temp);
		if(a.empty()){
			return temp;
		}
		else if(prev != a.head()){
			temp = ListOps.addtoendr(temp, a.head());
			prev = a.head();
			temp = removeDuplicate(a.tail(), temp, prev);
		}
		else {
			temp = removeDuplicate(a.tail(), temp, prev);
		}
		return temp;
    }
    
    // 15
	static List skip(int x, List a){
		return skip(x, a, new List());
	}
    static List skip(int x, List a, List temp) {
    	// Your code is in here
		if (a.empty()){
			return temp;
		}
		else if (a.head() == x){
			temp = skip(x, a.tail(), temp);
		}
		else if (a.head() != x){
			temp = ListOps.addtoendr(temp, a. head());
			temp = skip(x, a.tail(), temp);
		}
		return temp;
    }
}   
