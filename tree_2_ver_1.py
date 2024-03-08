# Define Node class for expression tree
class Node:
   def __init__(self, value):
       self.value = value # The value of the node, which can be a variable or an operator
       self.left = self.right = None # The left and right children of the node

# Function to print expression tree
def print_tree(root, indent=""):
   if root: # If node is not None
       print(indent + str(root.value)) # Print value of node
       print_tree(root.left, indent + " ") # Recursively print left subtree
       print_tree(root.right, indent + " ") # Recursively print right subtree

# Function to build expression tree from given expression
def build_expression_tree(expression):
   stack = [] # Stack to hold nodes
   current_node = None # The current node being processed

   # Iterate over each character in the expression
   for char in expression:
       if char.isalpha(): # If character is a variable
           stack.append(Node(char)) # Create new node with variable and add it to stack
       elif char in ['-', 'v', '^', '>']: # If character is an operator
           new_node = Node(char) # Create new node with operator
           new_node.right, new_node.left = stack.pop(), stack.pop() # Set right and left children of new node
           stack.append(new_node) # Add new node to stack
       elif char == '(': # If character is an opening parenthesis
           stack.append(current_node) # Push current node to stack
       elif char == ')': # If character is a closing parenthesis
           current_node = stack.pop() # Pop top node from stack and set it as current node

   return current_node # Return root of expression tree

# Run the code with an expression
expression = "(((-p) v q) -> (r -> p))"
root = build_expression_tree(expression)
print_tree(root) # Print expression tree

