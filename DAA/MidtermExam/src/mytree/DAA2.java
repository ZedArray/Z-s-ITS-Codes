package mytree;

// AVL Tree = Height-Balanced (HB) Tree

public class DAA2 extends DAA1 {

	// 4. isHeightBalanced() [10 points]
	public static boolean isHeightBalanced(MyTree t) {
		// Write your codes in here
        //...
        // Write your codes in here
		if (t.getEmpty()) {
			return true;
		}
		
		if (Math.abs(getHeight(t.getLeft()) - getHeight(t.getRight())) > 1) {
			return false;
		}
		
		return isHeightBalanced(t.getLeft()) && isHeightBalanced(t.getRight());
	}
	
	private static int getHeight(MyTree t) {
		if(t.getEmpty()) {
			return 0;
		}
		return (1 + Math.max(getHeight(t.getLeft()), getHeight(t.getRight())));
	}

	// 5. insertHB() [10 points]
	public static MyTree insertHB(int n, MyTree t) {
		// Write your codes in here
        //...
        // Write your codes in here
		if (t.getEmpty()) {
			return new MyTree(n, new MyTree(), new MyTree());
		}
		else if(n < t.getValue()) {
			MyTree _tempLeft = insertHB(n, t.getLeft());
			t = new MyTree(t.getValue(), _tempLeft, t.getRight());
		}
		else if(n > t.getValue()) {
			MyTree _tempRight = insertHB(n, t.getRight());
			t = new MyTree(t.getValue(), t.getLeft(), _tempRight);
		}
		
		int _bFactor = getBalanceFactor(t);
		
		if(_bFactor > 1 && n < t.getLeft().getValue()) {
			return rebalanceForRight(t);
		}
		if(_bFactor > 1 && n > t.getLeft().getValue()) {
			t = new MyTree(t.getValue(), rebalanceForLeft(t.getLeft()), t.getRight());
			return rebalanceForRight(t);
		}
		if(_bFactor < -1 && n > t.getRight().getValue()){
			return rebalanceForLeft(t);
		}
		if(_bFactor < -1 && n < t.getLeft().getValue()) {
			t = new MyTree(t.getValue(), rebalanceForRight(t.getLeft()), t.getRight());
			return rebalanceForRight(t);
		}
		
		return t;
	}
	
	private static int getBalanceFactor(MyTree t) {
		if(t.getEmpty()) {
			return 0;
		}
		return getHeight(t.getLeft()) - getHeight(t.getRight());
	}

	// rebalanceForLeft is called when the left subtree of t may have
	// grown taller by one notch.
	// If it is indeed taller than the right subtree by two notches,
	// return a height-balanced version of t using single or double rotations.
	// The subtrees of t are assumed to be already height-balanced and
	// no effort is made to rebalance them.
	//
	// Likewise, for the case of the right subtree -> rebalanceForRight
	// Both rebalanceForLeft & rebalanceForRight will be used by insertHB() and deleteHB()
	// 6. rebalanceForLeft() [15 points]
	private static MyTree rebalanceForLeft(MyTree t) {
		// Write your codes in here
        //...
        // Write your codes in here
		MyTree _newParent = t.getRight();
		MyTree _tempTree = _newParent.getLeft();
		t = new MyTree(t.getValue(), t.getLeft(), _tempTree);
		
		return new MyTree(_newParent.getValue(), t, _newParent.getRight());
	}
	
	// 7. rebalanceForRight() [15 points]
	private static MyTree rebalanceForRight(MyTree t) {
		// Write your codes in here
        //...
        // Write your codes in here
		MyTree _newParent = t.getLeft();
		MyTree _tempTree = _newParent.getRight();
		t = new MyTree(t.getValue(), _tempTree, t.getRight());
		
		return new MyTree(_newParent.getValue(), _newParent.getLeft(), t);
	}
	
	// 8. deleteHB() [10 points]
	/**
	 * Deletes the value 'x' from the given tree, if it exists, and returns the new
	 * Tree.
	 *
	 * Otherwise, the original tree will be returned.
	 */
	public static MyTree deleteHB(MyTree t, int x) {
		if (t.getEmpty()) {
			return t;
		}
		if (x > t.getValue()) {
			t = new MyTree(t.getValue(), t.getLeft(), deleteHB(t.getRight(), x));
		}
		else if (x < t.getValue()) {
			t = new MyTree(t.getValue(), deleteHB(t.getLeft(), x), t.getRight());
		}
		else {
			MyTree _temp = null;
			if (t.getLeft().getEmpty() || t.getRight().getEmpty()) {
				if (t.getLeft().getEmpty()) {
					_temp = t.getRight();
				}
				else if (t.getRight().getEmpty()) {
					_temp = t.getLeft();
				}
				
				if(_temp.getEmpty()) {
					_temp = t;
					t = new MyTree();
				}
				else {
					t = _temp;
				}
			}
			else {
				_temp = getLeftMost(t.getRight());
				t = new MyTree(_temp.getValue(), _temp.getLeft(), deleteHB(t.getRight(), _temp.getValue()));
			}
		}
		
		if (t.getEmpty()) {
			return t;
		}
		
		int _balanceFactor = getBalanceFactor(t);
		
		if(_balanceFactor > 1 && getBalanceFactor(t.getLeft()) >= 0) {
			return rebalanceForRight(t);
		}
		if(_balanceFactor > 1 && getBalanceFactor(t.getLeft()) < 0) {
			t = new MyTree(t.getValue(), rebalanceForLeft(t.getLeft()), t.getRight());
			return rebalanceForRight(t);
		}
		if(_balanceFactor < -1 && getBalanceFactor(t.getRight()) <= 0) {
			return rebalanceForLeft(t);
		}
		if(_balanceFactor < -1 && getBalanceFactor(t.getRight()) > 0) {
			t = new MyTree(t.getValue(), rebalanceForRight(t.getLeft()), t.getRight()); //right left
			return rebalanceForLeft(t);
        }
		
		return t;
	}
	
	public static MyTree getLeftMost(MyTree t) {
		MyTree _currentNode = t;
		while (!_currentNode.getLeft().getEmpty()) {
			_currentNode = new MyTree(_currentNode.getLeft().getValue(), _currentNode.getLeft().getLeft(), _currentNode.getLeft().getRight());
		}
		
		return _currentNode;
	}

}