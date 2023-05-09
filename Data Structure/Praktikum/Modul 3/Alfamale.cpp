#include <bits/stdc++.h>
using namespace std;

#define lli signed long long int
#define str string
#define dbl double

lli find_max(lli input1, lli input2)
{
	return (input1 > input2) ? input1 : input2;
}

class tree_node
{
public:
	lli key = NULL;
	lli price = NULL;
	char name[256];

	lli height = 1; //used for AVL Trees

	tree_node* parent = NULL;
	tree_node* left = NULL;
	tree_node* right = NULL;
};

class binary_tree
{
public:
	tree_node* root = new tree_node;
	tree_node* last;
	lli maxDepth = 0;

	void branch(lli leafNum, lli p, char name[256])
	{
		tree_node* node = root;
		lli currDepth = 0;

		if (node->key == NULL)
		{
			node->key = leafNum;
			node->price = p;
			strcpy(node->name, name);
			last = node;
			return;
		}

		tree_node* parent = node;
		while (node_exists(node))
		{
			parent = node;
			if (leafNum > node->key) node = node->right;
			else if (leafNum < node->key) node = node->left;
			currDepth += 1;
		}

		tree_node* cache = new tree_node;
		cache->parent = parent;
		cache->key = leafNum;

		if (leafNum > parent->key) parent->right = cache;
		else if (leafNum < parent->key) parent->left = cache;
		maxDepth = max(maxDepth, currDepth);

		last = cache;
	}

	void balance()
	{
		tree_node* node = last;
		while ((node_exists(node->parent)) && (abs(find_tilt(node)) <= 1))
		{
			//cout << "checking node: " << node->key << "; height: " << node->height << endl;
			node->parent->height = node->height + 1;
			node = node->parent;
		}

		//if (node_exists(node->left)) cout << "left : " << node->left->key << ", height: " << node->left->height << endl;
		//if (node_exists(node->right)) cout << "right : " << node->right->key << ", height: " << node->right->height << endl;

		lli tilt = find_tilt(node);
		//cout << "finalnode: " << node->key << "; found tilt of " << tilt << endl;
		if (tilt > 1)
		{
			if (last->key < node->right->key)
			{
				//cout << "entered condition" << endl;
				rotate_right(node->right);
			}
			rotate_left(node);
			maxDepth -= 1;
		}
		else if (tilt < -1)
		{
			//cout << "last: " << last->key << "; left: " << node->left->key << endl;
			if (last->key > node->left->key)
			{
				//cout << "entered rleft first" << endl;
				rotate_left(node->left);
			}
			rotate_right(node);
			maxDepth -= 1;
		}
	}

	bool node_exists(tree_node* node)
	{
		if (node == NULL) return false;
		else if (node->key == NULL) return false;
		else return true;
	}

	pair<tree_node*, lli> find(lli findKey)
	{
		tree_node* node = root;
		//cout << "find: [" << findKey << "," << findValue << "]" << endl;

		tree_node* res = new tree_node;
		lli* resDepth = new lli;
		*resDepth = -1;
		find_node(node, findKey, res, 0, resDepth);
		//cout << "found res: [" << res->key << "," << res->value << "] " << endl;
		/*
		if (node_exists(res->parent)) cout << "p: [" << res->parent->key << "," << res->parent->value << "]" << endl;
		if (node_exists(res->right)) cout << "r: [" << res->right->key << "," << res->right->value << "]" << endl;
		if (node_exists(res->left)) cout << "l: [" << res->left->key << "," << res->left->value << "]" << endl << endl;
		*/
		return { res, *resDepth };
	}

	void inorder()
	{
		tree_node* node = root;
		do_inorder(node);
		cout << endl;
	}

	void preorder()
	{
		tree_node* node = root;
		do_preorder(node);
		cout << endl;
	}

	void postorder()
	{
		tree_node* node = root;
		do_postorder(node);
		cout << endl;
	}

	void parse_inorder(vector<lli> inorder, binary_tree* tree, lli fromIdx, lli toIdx)
	{
		if (fromIdx > toIdx) return;

		lli midIdx = (fromIdx + toIdx + 1) / 2;
		tree->branch(inorder[midIdx]);

		parse_inorder(inorder, tree, fromIdx, midIdx - 1);
		parse_inorder(inorder, tree, midIdx + 1, toIdx);
	}

	void solve()
	{
		map<lli, lli>* sum = new map<lli, lli>;

		add_sum(sum, root, 0);

		for (auto jt = (*sum).begin(); jt != (*sum).end(); ++jt)
		{
			cout << jt->second << " ";
		}
		cout << endl;
	}

	void add_sum(map<lli, lli>* sum, tree_node* currNode, lli currRow)
	{
		(*sum)[currRow] += currNode->key;

		if (node_exists(currNode->right)) add_sum(sum, currNode->right, currRow + 1);
		if (node_exists(currNode->left)) add_sum(sum, currNode->left, currRow - 1);
	}

private:
	void print_key(tree_node* node)
	{
		cout << node->key << " ";
	}

	void do_inorder(tree_node* node)
	{
		if (node_exists(node))
		{
			do_inorder(node->left);
			print_key(node);
			do_inorder(node->right);
		}
	}

	void do_preorder(tree_node* node)
	{
		if (node_exists(node))
		{
			print_key(node);
			do_preorder(node->left);
			do_preorder(node->right);
		}
	}

	void do_postorder(tree_node* node)
	{
		if (node_exists(node))
		{
			do_postorder(node->left);
			do_postorder(node->right);
			print_key(node);
		}
	}

	lli find_height(tree_node* node)
	{
		if (node == NULL) return 0;
		else return node->height;
	}

	lli find_tilt(tree_node* node)
	{
		lli rightHeight = 0; lli leftHeight = 0;
		if (node_exists(node))
		{
			if (node_exists(node->right)) rightHeight = node->right->height;
			if (node_exists(node->left)) leftHeight = node->left->height;
		}
		return rightHeight - leftHeight;
	}

	void find_node(tree_node* node, lli findKey, tree_node* res, lli currDepth, lli* resDepth)
	{
		if ((node_exists(node)) && (res->key == NULL))
		{
			/*
			cout << "trucheck: [" << node->key << "," << node->value << "]" << endl;
			if (node_exists(node->parent)) cout << "p: [" << node->parent->key << "," << node->parent->value << "]" << endl;
			if (node_exists(node->right)) cout << "r: [" << node->right->key << "," << node->right->value << "]" << endl;
			if (node_exists(node->left)) cout << "l: [" << node->left->key << "," << node->left->value << "]" << endl << endl;
			*/

			if (node->key == findKey)
			{
				res->key = node->key;
				res->parent = node->parent;
				res->left = node->left;
				res->right = node->right;
				*resDepth = currDepth;
				return;
			}
			else
			{
				if (node_exists(node->left)) find_node(node->left, findKey, res, currDepth + 1, resDepth);
				if (node_exists(node->right)) find_node(node->right, findKey, res, currDepth + 1, resDepth);
			}
		}
	}

	void rotate_right(tree_node* max)
	{
		tree_node* min = max->left;
		tree_node* mid = min->right;

		if (node_exists(max->parent))
		{
			min->parent = max->parent;
			if (min->parent->right == max) min->parent->right = min;
			else if (min->parent->left == max) min->parent->left = min;
		}
		else
		{
			min->parent = NULL;
			root = min;
		}

		max->parent = min;
		min->right = max;
		max->left = NULL;

		if (node_exists(mid))
		{
			max->left = mid;
			mid->parent = max;
		}

		if (node_exists(min->left)) min->left->height = find_max(find_height(min->left->left), find_height(min->left->right)) + 1;
		if (node_exists(min->right)) min->right->height = find_max(find_height(min->right->left), find_height(min->right->right)) + 1;
		max->height = find_max(find_height(max->left), find_height(max->right)) + 1;
		min->height = find_max(find_height(min->left), find_height(min->right)) + 1;

		//cout << "rotated right" << endl;
	}

	void rotate_left(tree_node* min)
	{
		tree_node* max = min->right;
		tree_node* mid = max->left;

		if (node_exists(min->parent))
		{
			max->parent = min->parent;
			if (max->parent->right == min) max->parent->right = max;
			else if (max->parent->left == min) max->parent->left = max;
		}
		else
		{
			max->parent = NULL;
			root = max;
		}

		min->parent = max;
		max->left = min;
		min->right = NULL;

		if (node_exists(mid))
		{
			min->right = mid;
			mid->parent = min;
		}

		if (node_exists(max->left)) max->left->height = find_max(find_height(max->left->left), find_height(max->left->right)) + 1;
		if (node_exists(max->right)) max->right->height = find_max(find_height(max->right->left), find_height(max->right->right)) + 1;
		max->height = find_max(find_height(max->left), find_height(max->right)) + 1;
		min->height = find_max(find_height(min->left), find_height(min->right)) + 1;

		//cout << "rotated left" << endl;
	}
};

int main(){
    binary_tree tree;
    while(1){
        int id, price;
        char name[100];
        cin >> id >> price;
        scanf("%s", name);
        getchar();
        if (id == 0 && price == 0 && name[0] == '0'){
            //cout << "bye 1" << endl;
            break;
        }
        else{
            //cout << "hi 1" << endl;
            tree.branch(id, price, name);
        }
    }
	tree.balance();
	while(1){
        int input;
        cin >> input;
        if (input == 0){
            break;
        }
        else{
            set.get(input);
        }
    }
}