# Explain Basic Geomtry Concepts

## Problem A

- Time Note: 15 sec, then the complexity can reach O(N* N *N)
- Formula: Area = 0.5 \*[x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)]

### Hints

1. Dot Product
2. Pythagoras' theorem

## Problem D

> Notes for me: take care of using while loop and the variables declared inside (cnt, ans).

> Notes for me: while(n--), Don't use n after the while!!

## Problem E

- First Idea: sort, then try to go from each point to their adjacent (cw or ccw)
- Get the min angle possible then div by k and take the ceil
- Improved Idea: try to find max dist between each adj points to remove them from the path
- The Arc at the end will connect all adjacent points except two. Find them!

### ceil function

For positive numbers where you want to find the ceiling (q) of x when divided by y.

```cpp
unsigned int x, y, q;
To round up ...

q = (x + y - 1) / y;
or (avoiding overflow in x+y)

q = 1 + ((x - 1) / y); // if x !=0
```
