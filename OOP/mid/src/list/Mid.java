package list;

public class Mid extends List {

    // 8
    static List negateAll(List a) {
    	// Your code is in here
		// multiply the head by -1 and then recurse into a's tail if a is not empty
    	a.head *= -1;
    	if(!a.empty()) {
    		negateAll(a.tail());    		
    	}
    	return a;
    }

    // 9
	//index counter
    static int counter = 0;
    static int find(int x, List a) {
    	// Your code is in here
    	int index = 0;
		// if a is empty, then that means we've reached the end of the list without ever finding x. So we return -1
    	if (a.empty()) {
    		return -1;
    	}
		// checks if a's head matches with x. If not, then continue searching with a's tail as the new list.
    	else if (a.head != x) {
    		counter++;
    		index = find(x, a.tail());
    	}
		// If yes, we return the index using the index counter
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
		// default state is true, as we only check for it not being positive
    	boolean defState = true;
		// return true if a is empty (reached the end)
    	if (a.empty()) {
    		return true;
    	}
		// Will continue searching if a's head is positive
    	if(a.head() >= 0) {
    		defState = allPositive(a.tail());
    	}
		// If we get a hit on a's head not being positive, return false so the default state goes to false
    	else if (a.head() < 0) {
    		return false;
    	}
    	return defState;
    }

    // 11
	// helper function to have a new temporary list
	static List positives(List a){
		List temp = new List();
		return positives(a, temp);
	}
    static List positives(List a, List temp) {
    	// Your code is in here
		// we add go through the entire list using the usual check head and continue with tail and add the head to the temporary list only if the head is positive. Otherwise we continue searching until a is empty
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
		// as stated on MidTest.java, this function checks if the list is sorted incrementally. So we only check if the head is smaller than the tail's head. Using default state as false, the default state becomes true if the check goes until the end of the list
		boolean defState = false;
    	if (a.tail.empty()) return true;
		else if (a.head() <= a.tail.head()){
			defState = sorted(a.tail());
		}
    	return defState;
    }
    
    // 13
	// helper function
	static List merge(List a, List b){
		List tempList = new List();
		return merge(a, b, tempList);
	}
    static List merge(List a, List b, List temp) {
    	// Your code is in here
		// seeing as the merged list is supposed to be sorted, we check both lists' heads. Add the smallest one first, then recurse both list but keeping the unadded list normally and using the added list's tail as the new lists. They're added to a new temporary list which will be returned to be the new list
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
		return temp;
    }

    // 14
	// helper function
	static List removeDuplicate(List a){
		return removeDuplicate(a.tail(), new List(a.head(), List.nil()), a.head());
	}
	// we add two new variables from the helper fuction. the new temporary list which will be the one pushed into the new list in MidTest, and a previous number variable which is initialized with a's head
    static List removeDuplicate(List a, List temp, int prev) {
    	// Your code is in here
		// empty check
		if(a.empty()){
			return temp;
		}
		// if prev (previous number indicator) isn't the same as a's head, then add a's head into the new list and change prev into a's head preparing it for the next check
		else if(prev != a.head()){
			temp = ListOps.addtoendr(temp, a.head());
			prev = a.head();
			temp = removeDuplicate(a.tail(), temp, prev);
		}
		// if prev is the same as a's head we just keep recursing without adding to the temp list
		else {
			temp = removeDuplicate(a.tail(), temp, prev);
		}
		return temp;
    }
    
    // 15
	// helper function
	static List skip(int x, List a){
		return skip(x, a, new List());
	}
	// helper function adds an empty temporary list
    static List skip(int x, List a, List temp) {
    	// Your code is in here
		//empty check
		if (a.empty()){
			return temp;
		}
		// continue recursing without adding to the temporary list if current head is the same as x
		else if (a.head() == x){
			temp = skip(x, a.tail(), temp);
		}
		// add the head to the temp list if it isn't the same as x
		else if (a.head() != x){
			temp = ListOps.addtoendr(temp, a. head());
			temp = skip(x, a.tail(), temp);
		}
		return temp;
    }
}   
