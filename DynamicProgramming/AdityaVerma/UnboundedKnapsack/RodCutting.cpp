// Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces
// of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.


// Example 1:

// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by
// cutting in two pieces of lengths 2 and 
// 6, i.e., 5+17=22.

class Solution{
  public:
    int cutRod(int price[], int n) {
       
       int arr[n];
       for(int i=0;i<n;i++){
           arr[i]=i+1;
       }
        
       int t[n+1][n+1];
       for(int i=0;i<n+1;i++){
           for(int j=0;j<n+1;j++){
               if(i==0){
                   t[i][j]=0;
               }
               else if (j==0){
                   t[i][j]=0;
               }
           }
       }
       for(int i=1;i<n+1;i++){
          for(int j=1;j<n+1;j++){
              if(arr[i-1]<=j){
                  t[i][j]=max(price[i-1]+t[i][j-arr[i-1]],t[i-1][j]);
              }
              else if(arr[i-1]>j){
                  t[i][j]=t[i-1][j];
              }
          }
       }
       return t[n][n];
   }
};