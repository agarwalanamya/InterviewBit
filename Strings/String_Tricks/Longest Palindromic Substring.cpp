/*
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example : Input : "aaaabaaa"
          Output : "aaabaaa"
*/
/*
****** #### This Soulution uses DP and is correct but uses O(n2) space, Hence shows Segmentation Fault on InterviewBit. #### ******
I have given the solution which uses O(1) space and is accepted at InterviewBit.

string Solution::longestPalindrome(string A) {
int n = A.length();
    if(n==0){
        return "";
    }
    bool table[n][n];
    
    memset(table, 0, sizeof(table));
    
    int maxlen = 0;
    
    int start = 0;
    
    for(int i = 0; i < n; i++){
        table[i][i] = true;
        maxlen = 1;
    }
    
    for(int i = 0; i < n - 1; i++){
        if(A[i] == A[i+1]){
            table[i][i+1] = true;
            start = i;
            maxlen = 2;
        }
    }
    
    for(int len = 3; len <= n; len++){
        
        for(int i = 0; i < n - len + 1; i++){
            int j = i + len - 1;
            if(table[i+1][j-1] == true && A[i] == A[j]){
                table[i][j] = true;
                if(len > maxlen){
                    start = i;
                    maxlen = len;
                }
            }
            //j++;
        }
    }int n = str.size();  
  
    // table[i][j] will be false if substring str[i..j] 
    // is not palindrome. 
    // Else table[i][j] will be true 
    bool table[n][n]; 
      
    memset(table, 0, sizeof(table)); 
  
    // All substrings of length 1 are palindromes 
    int maxLength = 1; 
      
    for (int i = 0; i < n; ++i) 
        table[i][i] = true; 
  
    // check for sub-string of length 2. 
    int start = 0; 
    for (int i = 0; i < n-1; ++i) 
    { 
        if (str[i] == str[i+1]) 
        { 
            table[i][i+1] = true; 
            start = i; 
            maxLength = 2; 
        } 
    } 
  
    // Check for lengths greater than 2. k is length 
    // of substring 
    for (int k = 3; k <= n; ++k) 
    { 
        // Fix the starting index 
        for (int i = 0; i < n-k+1 ; ++i) 
        { 
            // Get the ending index of substring from 
            // starting index i and length k 
            int j = i + k - 1; 
  
            // checking for sub-string from ith index to 
            // jth index iff str[i+1] to str[j-1] is a 
            // palindrome 
            if (table[i+1][j-1] && str[i] == str[j]) 
            { 
                table[i][j] = true; 
  
                if (k > maxLength) 
                { 
                    start = i; 
                    maxLength = k; 
                } 
            } 
        } 
    } 
  
   cout << "Longest palindrome substring is: "; 
   printSubStr( str, start, start + maxLength - 1 ); 
      
    // return length of LPS 
    return maxLength; 
} 
}
*/

/*
This is acceptable, O(1) space complexity code.

string Solution::longestPalindrome(string A) {
    
    int length = A.length();
    int start = 0;
    int maxlength = 1;
    int low = 0;
    int high;
    
    for(int i = 1; i < length; ++i){
    
        low = i-1;
        high = i;
    
        while(low >= 0 && high < length && A[low] == A[high]){
            if(high - low + 1 > maxlength){
                start = low;
                maxlength = high - low + 1;
            }
            --low;
            ++high;
        }
        
        low = i-1;
        high = i+1;
        while(low >= 0 && high < length && A[low] == A[high]){
            if(high - low + 1 > maxlength){
                start = low;
                maxlength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    return A.substr(start, maxlength);
    
    
}
