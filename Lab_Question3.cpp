// 3.	Create a class Tensor with a method sort to sort a vector input argument and print it out. Please verify this correctness in main function    

// Answer-

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Tensor {
public:

    void sort(vector<int>& input) {
        std::sort(input.begin(), input.end());
        
       
        cout << "Sorted vector: ";
        for (int num : input) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    Tensor tensor;

    
    vector<int> input = {4, 2, 7, 1, 9};
    tensor.sort(input);

    return 0;
}

// Output-
//   Sorted vector: 1 2 4 7 9 
