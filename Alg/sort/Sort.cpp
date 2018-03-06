#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void merge(vector<int> array, vector<int>::iterator left, vector<int>::iterator mid, vector<int>::iterator right)
    {
        vector<int> array1 = vector<int>(left, mid);
        vector<int> array2 = vector<int>(mid, right);
        auto i = array1.begin();
        auto j = array2.begin();
        while (i < array1.end() && j < array2.end())
        {
            if (*i < *j)
                *(left++) = *(i++);
            else *(left++) = *(j++);
        }
        while (i < array1.end())
            *(left++) = *(i++);
        while (j < array2.end())
            *(left++) = *(j++);
    }

    void mergeSortHelper(vector<int> array, vector<int>::iterator left, vector<int>::iterator right)
    {
        if (left < right-1)
        {
            auto mid = left + (right - left) / 2;
            mergeSortHelper(array, left, mid);
            mergeSortHelper(array, mid, right);
            merge(array, left, mid, right);
        }
    }

    vector<int>::iterator partition(vector<int> array, vector<int>::iterator low, vector<int>::iterator high)
    {
        int value = *low;
        while (low < high)
        //from wiki -> should swap the inverted pair(low, high). Low is the one greater than or equal to, and high is the one less than or equal to.
        {
            while (*low < value && low < high)
            {
                low++;
            }
            while (*high > value && low < high)
            {
                high--;
            }
            if (low >= high)
                return high;
            iter_swap(low, high);
        }
        return high;
    }

    void quickSortHelper(vector<int> array, vector<int>::iterator low, vector<int>::iterator high)
    {
        if (low < high)
        {
            auto pivotIndex = partition(array, low, high);
            quickSortHelper(array, low, pivotIndex-1);
            quickSortHelper(array, pivotIndex+1, high);
        }
    }

public:
    vector<int> rainbowSort(vector<int> array) 
    // put the negative numbers in left, 0s in middle and positive numbers in right.
    // indeed it's quick sort partition assuming no need to keep the original order.
    {
        auto neg = array.begin();
        auto zero = neg;
        auto pos = array.end()-1;
        while (zero <= pos)// equal is important as the index of zero points to unknown number
        {
            while (*pos > 0)
                pos--;
            while (*zero == 0)
                zero++;
            if (zero > pos)
                break;
            if (*zero < 0)
            {
                iter_swap(neg++, zero++);
            }
            else iter_swap(zero, pos--);
        }
        return array;
    }

    vector<int> moveZero(vector<int> array) 
    // move 0s to the end assuming no need to keep the original order.
    {
        auto left = array.begin();
        auto right = array.end()-1;
        while (left <= right)
        {
            while (*left != 0)
                left++;
            while (*right == 0)
                right--;
            if (left > right)
                break;
            iter_swap(left++, right--);
        }
        return array;
    }

    vector<int> quickSort(vector<int> array)
    {
        if (array.empty()) return *new vector<int>;
        quickSortHelper(array, array.begin(), array.end()-1);
        return array;
    }

    vector<int> mergeSort(vector<int> array)
    {
        if (array.empty()) return *new vector<int>;
        mergeSortHelper(array, array.begin(), array.end());
        return array;
    }

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
    array = sol -> mergeSort(array);
    for (int i : array)
    {
        cout << i << ",";
    }
    return 0;
}