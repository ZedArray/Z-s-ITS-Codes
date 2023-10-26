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
    static List positives(List a) {
    	// Your code is in here
    	List tempList = new List();
    	if (a.empty()) return tempList;
    	else if (a.head() >= 0) {
    		tempList = ListOps.addtoendr(tempList, a.head());
    	}
    	tempList = positives(a.tail());
    	return tempList;
    }

    // 12
    static boolean sorted(List a) {
    	// Your code is in here
    }
    
    // 13
    static List merge(List a, List b) {
    	// Your code is in here
    }

    // 14
    static List removeDuplicate(List a) {
    	// Your code is in here
    }
    
    // 15
    static List skip(int x, List a) {
    	// Your code is in here
    }
}   
