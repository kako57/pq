# pq
---

pq is a rational roots finder for polynomial equations;

UPDATE: pq now supports rational coefficients!

---
## Example

Enter the polynomial coefficients in decreasing power as arguments to the program

```
$ # solve a polynomial equation in degree 8
$ ./pq 1 -28 322 -1960 6769 -13132 13068 -5040 0
Rational roots:
7
6
5
4
3
2
1
0
```

## Rational coefficients!

pq now supports rational coefficients in polynomial equations

```c
$ # solve a polynomial equation with rational coefficients
$ ./pq 1 1 1/4
Rational roots:
-1/2
```
