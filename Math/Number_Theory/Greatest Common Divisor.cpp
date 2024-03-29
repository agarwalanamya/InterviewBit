/*
Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.

Example

m : 6
n : 9

GCD(m, n) : 3 
*/

/*
Solution lies in Euclidean Theorem which states, for A > B,  GCD(A, B) = GCD(A - B, B).

It also states, for any integers A and B, GCD(A, B) = GCD(B, A % B).

It reduces to a simple recursion after this.

*/



int Solution::gcd(int A, int B) {
    if( B == 0 )
        return A;
    return gcd( B, A % B );
}

/*
Another solution involving just the usage of GCD(A, B) = GCD(A - B, B) for A>B, is given below.
*/
/*

int Solution::gcd(int A, int B) {
    if( B == 0 )
        return A;
    if( A == 0 )
        return B;
    if( A > B)
        return gcd(A-B, B);
    return gcd(A, B - A);    
}

*/
