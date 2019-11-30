/*
You are in an infinite 2D grid where you can move in any of the 8 directions :

 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.

Example :

Input : [(0, 0), (1, 1), (1, 2)]
Output : 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).

*/

int shortestDist(int a1, int a2, int b1, int b2){
    
    int dx = abs(a2 - a1);
    int dy = abs(b2 - b1);
    
    return max(dx, dy);
}

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int count = 0;
    
    for(int i = 0; i < A.size() - 1; i++){
        count += shortestDist(A[i], A[i+1], B[i], B[i+1]);
    }
    
    return count;
}
