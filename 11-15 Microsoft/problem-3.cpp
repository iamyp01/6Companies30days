/*
Link : https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/#
Author : Yuvraj Parashar
*/

void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    // Step: 1 => find the transpose of the matrix
    // Step: 2 => swap rows [1-n], [2, n-1]...
    
    // here we are getting transpose of the matrix 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // here we are swapping the rows
    int i = 0, j = n-1;
    while(i <= j){
        for(int k = 0; k < n; k++){
            swap(matrix[i][k], matrix[j][k]);
        }
        i++; j--;
    }
}