/*
Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

Input Format:

    First and only argument of input contains an integer array A
Output Format:

    return a single integer denoting minimum xor value
Constraints:

2 <= N <= 100 000  
0 <= A[i] <= 1 000 000 000
For Examples :

Example Input 1:
    A = [0, 2, 5, 7]
Example Output 1:
    2
Explanation:
    0 xor 2 = 2
Example Input 2:
    A = [0, 4, 7, 9]
Example Output 2:
    3
*/
/*
The commented out part is a O(n2) solution, whereas the code, which is not commented is O(nlog(n)) solution.
InterviewBit accepts O(nlog(n))
*/

int Solution::findMinXor(vector<int> &A) {
    int minxor = INT_MAX;
    /*for(int i = 0; i < A.size(); i++){ 
        int x = A[i];
        for(int j = i+1; j < A.size(); j++){
            if(i == j){
                continue;
            }
            int xorvalue = x ^ A[j];
            if(xorvalue < minxor){
                minxor = xorvalue;
            }
        }
    }*/
    sort(A.begin(), A.end());
    int val = 0;
    for(int i = 0; i < A.size() - 1; i++){
        val = A[i] ^ A[i+1];
        minxor = min (val, minxor);
    }
    return minxor;
}
