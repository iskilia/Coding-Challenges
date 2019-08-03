#!/bin/python

import math
import os
import random
import re
import sys

# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
    myList = [0] * (n+1)
    for q in queries:
        [a,b,k] = q
        myList[a-1] += k
        if(b <= len(myList)):
            myList[b] -= k
    maxVal = x = 0

    for num in myList:
        x += num
        if(maxVal < x):
            maxVal = x

    return maxVal

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = raw_input().split()

    n = int(nm[0])

    m = int(nm[1])

    queries = []

    for _ in xrange(m):
        queries.append(map(int, raw_input().rstrip().split()))

    result = arrayManipulation(n, queries)

    fptr.write(str(result) + '\n')

    fptr.close()
