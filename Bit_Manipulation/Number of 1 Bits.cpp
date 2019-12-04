/*
Write a function that takes an unsigned integer and returns the number of 1 bits it has.

Example:

The 32-bit integer 11 has binary representation

00000000000000000000000000001011
so the function should return 3.
*/
/*
Solution - The idea is to the iterations taken to unset the set bits.
The solution given traverses through every bit and then checks if the right most bit is set or not and then shifts the binary number 
by one to the right.

Another approach to reduce the number of iterations can be done by using Brian Kernighan's Algo. 
There we transform the number by using bitwise &, by doing A = A & (A-1). This reduces the number of itearations and number of set bits is 
the number of times loop runs.
*/
int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int count = 0;

    while(A != 0){
        if( A & 1 ){
            ++count;
        }
        A >>= 1;
    }
    // This can be  done to implement Brian Kernighan's Algo.
    /*
    while( A != 0){
        A &= A-1;
        ++c;
    }
    */  
    return count;
}
