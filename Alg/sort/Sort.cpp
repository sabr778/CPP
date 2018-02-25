#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> selectionSort(vector<int> array)
    {
        if (array.empty()) return *new vector<int>;
        for (auto i = array.begin(); i < array.end(); i++)
        {
            auto j = i;
            auto imin = i;
            for (; j < array.end(); j++)
            {
                if (*j < *imin)
                    imin = j;
            }
            iter_swap(i, imin);
        }
        return array;
    }

public:
    vector<int> insertionSort(vector<int> array)
    {
        if (array.empty()) return *new vector<int>();
        for (int count = 1; count < array.size(); count++)
        {
            int key = array[count];
            int j = count-1;
            while (j >=0 && array[j] >= key) 
            {
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = key;
        }
        return array;
    }

public:
    vector<int> bubbleSort(vector<int> array)
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