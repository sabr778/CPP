class Iteration {
public:
  	//Synopsis: Given an array A[0]...A[n-1] of integers, find out the length of the longest ascending subsequence.
  	//Assumptions: A is not null
  	//time complexity O(n square) is not accepted.
  	int longestIncreasingSequence(vector<int> array)
	{
	    int length = array.size();
	    if (length < 2) return 1;
	    vector<int> ret(length);
	    ret.at(0) = 1;
	    for (int i = 1; i < length; i++)
	    {
	        ret.at(i) = 1;
	        for (int j = 0; j < i; j++)
	        {
	            if (array.at(j) < array.at(i) && ret.at(j) + 1 > ret.at(i))
	                ret.at(i) = ret.at(j) + 1;
	        }
	    }
	    int max = ret.at(0);
	    for (int i = 1; i < length; i++)
	    {
	        if (ret.at(i) > max) max = ret.at(i);
	    }
	    return max;
	}


	//1. If A[i] is smallest among all end candidates of active lists, we will start new active list of length 1.
	//2. If A[i] is largest among all end candidates of active lists, we will clone the largest active list, and extend it by A[i].
	//3. If A[i] is in between, we will find a list with largest end element that is smaller than A[i]. Clone and extend this list by A[i]. We will discard all other lists of same length as that of this modified list.
	//https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
	//optimized: O(nlgn) time complexity and O(n) space complexity
	int longest(vector<int> array)
	{
		if (array.size() < 2) return array.size();
		int ret[array.size()];
		int length = 1;
		ret[0] = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			if (array[i] < ret[0])
				ret[0] = array[i];
			else if (array[i] > ret[length -1])
				ret[length++] = array[i];
			else if (array[i] > ret[0] && array[i] < ret[length -1])
			{
				int cellIndex = cellIndex(ret, 0, length-1, array[i]);
				ret[cellIndex+1] = array[i];
			}
		}
		return length;
	}

private:
	int cellIndex(int array[], int left, int right, int key)
	{
		while (left < right -1)
		{
			int mid = left + (right - left) / 2;
			if (array[mid] < key) left = mid;
			else right = mid;
		}
		return array[right] < key ? right : left;
	}

};