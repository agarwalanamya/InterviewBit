/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False
*/

/*
The approach is quite easy. 
From the given number, make the reverse number. 
If the given number and the obtained number are equal, return true, otherwise return false.

*/

int Solution::isPalindrome(int A) {

    if(A < 0){
        return false;
    }
    
    auto tmp = A;
    auto res = tmp * 0;
    
    while(tmp != 0){
        res = (tmp % 10) + (res * 10);
        tmp /= 10;
    }
    if( res == A){
        return true;
    }
    else{
        return false;
    }
}
