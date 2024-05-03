from sympy import sympify, symbols

expression = "x**2 + 3 * x - 1"
x = symbols('x')
my_function = sympify(expression)
result = my_function.subs(x, 2)
print(result)  # Output: 9

input = "1+1"
if input[0].isdigit():
    print(eval(input))
else:
    print(input)
