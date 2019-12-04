/*
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 
*/

vector<bool> allprimesbelow(vector<bool> primes){ // This function returns the vector, true only at those indices, which are prime smaller than the given number
    for(int p = 2; p <= primes.size(); p++){
        if( primes[p] == true){
            for(int j = p*p; j <= primes.size(); j = j + p){
                primes[j] = false;
            }
        }
    }
    return primes;
}

vector<int> Solution::primesum(int A) {
    vector<bool> primes(A + 1, true);
    
    primes[0] = false;
    primes[1] = false;

    primes = allprimesbelow(primes);
    
    vector<int> res(2);
    
    for(int i = 2; i <= A/2; i++){
        if(primes[i] == true && primes[A - i] == true){
            res[0] = i;
            res[1] = A - i;
            return res;
        }
    }
}
