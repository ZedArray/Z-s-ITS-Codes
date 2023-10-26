package tree;

/** Binary trees with nodes labelled by integers */
public class Tree {
	private int root;
	private Tree left, right;

	/** Creates a new instance of Tree: a branch */
	public Tree(int root, Tree left, Tree right) {
		this.root = root;
		this.left = left;
		this.right = right;
	}

	/**
	 * Creates a new instance of Tree: a leaf (a special case
	 * of the above) */
	public Tree(int root) {
		this.root = root;
		this.left = null;
		this.right = null;
	}

	/** Sample method: Mirror myself */
	public void mirror() {
		if (left != null) { // Left branch, please mirror yourself
			left.mirror();  // This works by delegation
		}
		if (right != null) { // Right branch, please mirror yourself
			right.mirror();  // This works by delegation
		}
		Tree originalLeft = left; // Swap the branches, mirror myself
		left = right;
		right = originalLeft;
	}
	
	/**
	 * Converts a tree to an expression-tree string representation
	 */
	@Override
	public String toString() {
		String sleft, sright;

		// Convert the left and right branches to strings,
		// delegating the task to them if they exist.
		if (left == null) {
			sleft = "empty";
		} else {
			sleft = left.toString(); // Please do your job, Mr. Left Subtree.
		}
		if (right == null) {
			sright = "empty";
		} else {
			sright = right.toString(); // Please do your job, Mrs. Right Subtree.
		}
		// Now I do my own job:
		String s = "branch(" + root + "," + sleft + "," + sright + ")";
		return s;
	}

	/**
	 * Converts a tree to an expression-tree string representation (advanced)
	 */
	public String toStringAdv() {
		return this.toStringFrom(0);
	}
	public String toStringFrom(int depth) {
		int step = 4; // Depth step (number of spaces printed)

		// Delegate task to Mr. Left Subtree, if necessary:
		String sleft;
		if (left != null) {
			sleft = left.toStringFrom(depth + step);
		} else {
			sleft = "";
		}
		// Delegate task to Mrs. Right Subtree, if necessary:
		String sright;
		if (right != null) {
			sright = right.toStringFrom(depth + step);
		} else {
			sright = "";
		}
		// My own task now:
		String s = sright + spaces(depth) + root + "\n" + sleft;
		return s;
	}
	private String spaces(int n) {
		String s = "";
		for (int i = 0; i < n; i++) {
			s = s + " ";
		}
		return s;
	}
	
	// 2
	public void triple() {
		//multiplies the root node by 3 and then recurse it on the left and right nodes if they are not empty
		this.root *= 3;
		if (this.right != null) {
			right.triple();
		}
		if (this.left != null) {
			left.triple();
		}
		
	}
	
	// 3
	public void printDepthFirst() {
		// Your code is in here
		// prints the root node and then call the function on the left node first and then the right node
		System.out.println(this.root + " ");
		if (this.left != null) {
			left.printDepthFirst();
		}
		if (this.right != null) {
			right.printDepthFirst();
		}
	}

	// 4
	public Tree createFreshCopy() {
		// Your code is in here
		// initialize 3 temporary trees, one for overall, and the rest for left and right subtree
		Tree tempTree = null;
		Tree leftTemp = null;
		Tree rightTemp = null;
		// we call the function on left and right node to create copies of the left and right subtree
		if (left != null){
			leftTemp = left.createFreshCopy();
		}
		if (right != null) {
			rightTemp = right.createFreshCopy();
		}
		// then we return the tree using the left and right subtree copies and the current tree's root
		tempTree = new Tree(this.root, leftTemp, rightTemp);
		return tempTree;
	}

	// 5
	public int saveDepthFirst(int a[], int whereToStart) {
		// Your code is in here
		// we store the root on the designated position
		a[whereToStart] = root;
		// we then call it on both sides (left side prioritized because DFS)
		if (this.left != null) {
			whereToStart = left.saveDepthFirst(a, whereToStart+1);
		}
		if (this.right != null) {
			whereToStart = right.saveDepthFirst(a, whereToStart+1);
		}
		// and then we return the next designated position
		return whereToStart;
	}
	
	// 6
	public Tree find(int n) {
		// Your code is in here
		// a new tree to store the searched subtree
		Tree sought = null;
		// go search on the left side if n is smaller than the current root node
		if (n < root && left != null) {
			left.find(n);
		}
		// go search on the right side if n is bigger than the current root node
		else if (n > root && right != null) {
			right.find(n);
		}
		// when we reach the subtree where the root is equals to n, we give that subtree to the "sought" variable and then return that
		else if (n == root){
			// System.out.println("found it");
			sought = this;
		}
		return sought;
	}
	
	// 7 
	public Tree insert(int n) {
		// Your code is in here
		// we do this one by doing a similar search as the previous one. only now we're trying to find a null to insert n into the tree. For both sides, when we find a non null, we call the function on that side. But if we find a null, we create a new tree as a subtree on that null, using n as the root node
		if (n < root) {
			if (left != null) {
				left.insert(n);				
			}
			else if (left == null) {
				left = new Tree(n);
			}
		}
		else if (n > root) {
			if (right != null) {
				right.insert(n);
			}
			else if (right == null) {
				right = new Tree(n);
			}
		}
//		else if (n == root){
//			System.out.println("found it");
//			return this;
//		}
		return this;
	}
}
