import sys
from random import randint

if(len(sys.argv) < 3):
  print("Not enough arguments. (*.py <num polynomials> <size polynomials>")
else:
  num_polynomials = str(sys.argv[1])
  size_polynomials = str(sys.argv[2])

  f = open((num_polynomials + "x" + size_polynomials + ".dat"), 'w')

  f.write(num_polynomials + '\n')
  for i in range(int(num_polynomials)):
    f.write(size_polynomials + " ")
    for j in range(int(size_polynomials)):
      f.write(str(randint(-10, 10)) + " " + str(randint(0, 10)) + " ")
    f.write("\n")
