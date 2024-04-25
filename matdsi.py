from sympy import symbols, cos, dotprint
from graphviz import Source

a, b, c, x= symbols('a b c x')
expr = a * b * cos( c * x ) + b

src = Source(dotprint(expr))

src.render('output.gv', view=True)