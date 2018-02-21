#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> solve(vector<int> array)
    {
        if (array.empty()) return *new vector<int>();
        for (int count = 1; count < array.size(); count++)
        {
            bool swapped = false;
            for (auto j = array.begin() ; j < array.end()-count; ++j)
            {
                if (*(j) > *(j+1))
                {
                    iter_swap(j, j+1);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
        return array;
    }
};

int main() {
    int arr[] = {5,7,10,9,8,1,3,6,4,2};
    auto *sol = new Solution;
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    array = sol->solve(array);
    for (int i : array)
    {
        cout << i << ",";
    }
    return 0;
}