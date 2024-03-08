import ast
import re
import tkinter as tk

global postfix

class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def createBinaryTree(node_data):
    if node_data is None:
        return None
    if (type(node_data) != tuple):
        value = node_data
        node = TreeNode(value)
    elif node_data[0] == '¬' or node_data[0] == '~' or node_data[0] == '!':
        value, left_data = node_data
        node = TreeNode(value)
        node.left = createBinaryTree(left_data)
    else:
        value, left_data, right_data = node_data
        node = TreeNode(value)
        node.left = createBinaryTree(left_data)
        node.right = createBinaryTree(right_data)
    return node

def drawTree(node, x, y, canvas, level=1):
    if node is not None:
        if node.left:
            canvas.create_line(x, y, x + (512/2 ** level), y + 96, fill="#AAA", width=3)
            drawTree(node.left, x + (512/2 ** level), y + 96, canvas, level + 1)
        if node.right:
            canvas.create_line(x, y, x - (512/2 ** level), y + 96, fill="#AAA", width=3)
            drawTree(node.right, x - (512/2 ** level), y + 96, canvas, level + 1)
        canvas.create_oval(x - 20, y - 20, x + 20, y + 20, fill="#FFF", width=2)
        canvas.create_text(x, y, text=str(node.value), font=("Readex Pro", 16))

def isOperator(c):
    return (not c.isalpha()) and (not c.isdigit())

def getPriority(c):
    if c == '-' or c == '+' or c == '¬' or c == '~':
        return 1
    elif c == '*' or c == '/' or c == '∧':
        return 2
    elif c == '^' or c == '∨':
        return 3
    elif c == '→':
        return 4
    elif c == '↔':
        return 5
    return 0

def infixToPostfix(infix):
    infix = '(' + infix + ')'
    l = len(infix)
    char_stack = []
    output = []
 
    for i in range(l):
        if infix[i].isalpha() or infix[i].isdigit():
            output += infix[i]
        elif infix[i] == '(':
            char_stack.append(infix[i])
        elif infix[i] == ')':
            while char_stack[-1] != '(':
                output += char_stack.pop()
            char_stack.pop()
         
        # Found an operator
        else:
            if isOperator(char_stack[-1]):
                if infix[i] == '^':
                    while getPriority(infix[i]) <= getPriority(char_stack[-1]):
                        output += char_stack.pop()
                else:
                    while getPriority(infix[i]) < getPriority(char_stack[-1]):
                        output += char_stack.pop()
                char_stack.append(infix[i])
    while len(char_stack) != 0:
        output += char_stack.pop()
    return output
root_window = tk.Tk()

entry_label = tk.Label(root_window, text="enter equation below:")
entry_label.pack()
entry = tk.Entry(root_window)
entry.pack()

def getTreeTup():
    output = []
    if isOperator(postfix[0]):
        if isOperator(postfix[1]):
            output.append(postfix[0])
            postfix.pop(0)
            output.append(getTreeTup())
        else:
            if postfix[0] == '!' or postfix[0] == '¬' or postfix[0] == '~':
                output.append(postfix[0])
                postfix.pop(0)
                output.append(postfix[0])
                postfix.pop(0)
                return output
            else:
                output.append(postfix[0])
                postfix.pop(0)
                output.append(postfix[0])
                postfix.pop(0)
    else:
        output.append(postfix[0])
        postfix.pop(0)
    
    if len(postfix) > 0:
        if isOperator(postfix[0]):
            output.append(getTreeTup())
        else:
            output.append(postfix[0])
            postfix.pop(0)
    return output

def to_tuple(lst):
    return tuple(to_tuple(i) if isinstance(i, list) else i for i in lst)

def getInput():
    input_text = entry.get()
    global postfix
    postfix = infixToPostfix(str(input_text))[::-1]
    canvas.delete("all")
    canvas.create_text(512, 20, text=postfix, font=("Readex Pro", 12))
    root = createBinaryTree(to_tuple(getTreeTup()))
    drawTree(root, 512, 64, canvas)

entry_submit = tk.Button(root_window, text="calculate", command=getInput)
entry_submit.pack()
canvas = tk.Canvas(root_window, width=1024, height=512)
canvas.pack()
root_window.mainloop()