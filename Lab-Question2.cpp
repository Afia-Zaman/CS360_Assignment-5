// 2.	Find a function with one argument, vector of vectors named vals, for coordinates of one of its elements in row and 
// col to print the values that lie on the lower-left to upper-right diagonal of vals. After that, verify it in main function.


// Answer-

#include <iostream>
#include <vector>

using namespace std;

void print_diagonal_values(const vector<vector<int>>& vals) {
    int rows = vals.size();
    int cols = vals[0].size() > 0 ? vals[0].size() : 0;
    
    // Determine the length of the diagonal
    int diagonal_length = min(rows, cols);
    
    // Print the values on the diagonal
    for (int i = 0; i < diagonal_length; ++i) {
        cout << vals[i][i] << " ";
    }
    cout << endl;
}


int main() {
    // Example input 
    vector<vector<int>> vals = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Diagonal values:" << endl;
    print_diagonal_values(vals);

    return 0;
}

// Output-
  
// Diagonal values:
// 1 5 9 
