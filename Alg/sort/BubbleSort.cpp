#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    cout << "Hello World!" << endl;
	return 0;
}

class Solution
{
public:
    vector<int> solve(vector<int> array)
    {
        if (array.empty()) return *new vector<int>();
        for (int count = 0; count < array.size();)
        {
            count ++;
            for (vector<int>::iterator j = array.begin() ; j != array.end()-count; ++j)
            {
                if (*(j) > *(j+1))
                {
                    iter_swap(j, j+1);
                }
            }
        }
        return array;
    }
};