/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
*/
/*
Solution-
There are 2 ideas :
					1) Space - O(1), Time - O(n)
					2) Space - O(n), Time - O(n)
Idea 1 - 
		Here we consider the given array as a linked list where each element of the array is pointing towards the value at that index.
		Let's take an example to understand this. arr = { 1, 2, 3, 4, 5, 6, 3 }
		
		1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 3
		
		We consider this as a linked list with a cycle formed by 6 pointing towards the earlier 3.
		
		Now, to first find the presence of the cycle we use floyd's cycle finding algorithm, using two pointers, slow and fast. slow moves 1 step at a time, by slow = arr[slow], and fast moves 2 steps at a time, by fast = arr[arr[fast]].
		
		When slow = fast, this means, we have a cycle in the linked list that we are considering. And the starting point of the cycle is the element which is repeating.
		
		To find the starting point, we put fast = 0 and start moving both fast and slow by one step each. When fast = slow, we get the starting point of the cycle, hence the element in the array which is repeating.
		
Idea 2 - 
		Here we make a bool array, of size arr.size() + 1, and inititialise it as false. Now as we traverse the given array, we start toggle the false to true at each arr[i] th index of the boolean array. Whenever, we encounter true already present at any position of the boolean array, that particular index of the boolean array, is the element in the given array that is a duplicate.
		
		Here is the code for Idea 2, code for Idea 1 is given below out of the comment section.
		
		****************************************************
		
		vector <bool> val(A.size()+1, false);
    
    	for(int i = 0; i < A.size() ;i++){
        	if(v[A[i]]==true){
            	return A[i];
        	}
			
        	v[A[i]] = true;
    	}
    
    	return -1;
		***************************************************
*/

	int n = A.size();
    
    if(n <= 1){
        return -1;
    }
	
    int slow = A[0];
    int fast = A[A[0]];
    
    while(slow != fast){
        
        slow = A[slow];
        fast = A[A[fast]];
    }
    
    fast = 0;
    
    while(slow != fast){
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
