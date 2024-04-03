// 1. Write a function that takes a vector of integers as argument and reverses its elements.
// void rvrs(Vector<int>& vct){
// //Complete your program
// }

// Answer:

#include<iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void rvrs(std::vector<int>& vct) {
    reverse(vct.begin(), vct.end());
}

// Example 
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    rvrs(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}

// Output-

//   5 4 3 2 1
