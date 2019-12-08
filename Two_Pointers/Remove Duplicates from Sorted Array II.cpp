/*

Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,
Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].
*/

/*
Solution Approaches
  1) Start from the end of the array. When 2 instances of the same number are encountered, start removing the number unless you encounter
     a new number.
  2) Maintain two pointers, i and j. One (i) to traverse through the whole array, and the other (j) only to move forward when
     A[i] != A[i+1] || A[i] != A[i+2]. By doing this we are first traversing through the cluster of the duplicates which are present and
     start moving the second pointer forward only when first pointer has reached a position where it is either the second last or the last
     duplicate of that cluster. Hence fulfilling our purpose.
*/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // Approach 1
    int count= 0;          
    
    int size = A.size();
    
    for(int i = size - 1; i > 0 ; --i){
        if(A[i] == A[i-1]){
            if(count == 0){
                count = 1;
            }
            else{
                A.erase(A.begin() + i);
                size--;
            }
        }
        else{
            count = 0;
        }
    }
    return A.size();
    
    /*
    // Approach 2
    int count = 0;
    int n = A.size();
    
    for(auto i = 0; i < n; ++i){
        if( (i < n - 2) && (A[i] == A[i+1]) && (A[i] == A[i+2])){
            continue;
        }
        else{
            A[count] = A[i];
            count += 1;
        }
    }
    return count;
    */
}
