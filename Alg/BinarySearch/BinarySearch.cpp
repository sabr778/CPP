class BinarySearch
{
public:
	int classic(vector<int> input, int target) 
	{
        //If found return the index of it, otherwise return -1.
    	if (input.empty()) return -1;
    	auto left = input.begin();
    	auto right = input.end()-1;
    	while (left <= right)
    	{
    		auto mid = left + (right - left)/2;
    		if (*mid == target) return mid - input.begin();
    		else if (*mid < target) left = mid+1;
    		else right = mid-1;
    	}
    	return -1;
  	}


  	int firstOccur(vector<int> input, int target) 
  	{
        //If found duplicated return the index of the firstly occurred, otherwise return -1.
  		if (input.empty()) return -1;
    	auto left = input.begin();
    	auto right = input.end()-1;
    	while (left < right -1)
    	{
    		auto mid = left + (right - left)/2;
    		if (*mid >= target) right = mid;
    		else left = mid;
    	}
    	return *left == target ? left - input.begin() : (*right == target ? right - input.begin() : -1);
  	}

    int lastOccur(vector<int> input, int target) 
    {
        //If found duplicated return the index of the lastly occurred, otherwise return -1.
        if (input.empty()) return -1;
        auto left = input.begin();
        auto right = input.end()-1;
        while (left < right -1)
        {
            auto mid = left + (right - left)/2;
            if (*mid <= target) left = mid;
            else right = mid;
        }
        return *right == target ? right - input.begin() : ( *left == target ? left - input.begin() : -1);
    }

    int findClosest(vector<int> input, int target) 
    {
        //find the index of the number closest to the target. If empty vector return -1.
        if (input.empty()) return -1;
        auto left = input.begin();
        auto right = input.end()-1;
        while (left < right -1)
        {
            auto mid = left + (right - left)/2;
            if (*mid == target) return mid - input.begin();
            if (*mid < target) left = mid;
            else right = mid;
        }
        return abs(*left - target) <= abs(*right - target) ? left - input.begin() : right - input.begin();
    }

    vector<int> kClosest(vector<int> array, int target, int k) 
    {
        //assume array is not empty, and 0 <= k <= array.size()
        vector<int> ret = vector<int>(k);
        if (k == 0) return ret;
        int pivot = findClosest(array, target);
        ret[0] = *(array.begin() + pivot);
        auto left = array.begin() + pivot-1;
        auto right = array.begin() + pivot+1;
        int i = 1;
        while (i < k && left >= array.begin() && right < array.end())
        {
            if (abs(*left - target) <= abs(*right - target))
                ret[i++] = *(left--);
            else ret[i++] = *(right++);
        }
        while (i < k && left >= array.begin())
        {
            ret[i++] = *(left--);
        }
        while (i < k && right < array.end())
        {
            ret[i++] = *(right++);
        }
        return ret;
    }

    // class UnknownSizeVector {
    //  public:
    //   int get(int index) {
    //     // Return INT_MIN if out of bound,
    //     // otherwise return the element value.
    //   }
    // }

    //Given an integer dictionary A of unknown size, where the numbers in the dictionary are sorted in ascending order, determine if a given target integer T is in the dictionary. Return the index of T in A, return -1 if T is not in A.
    int searchUnknownSizeArray(UnknownSizeVector input, int target) 
    {
        if (input.get(0) == target)
            return 0;
        int left = 1, right = 10;
        while (input.get(right) < target && input.get(right) != INT_MIN)
        {
            left = right;
            right *= 10;
        }
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if (input.get(mid) == target) return mid;
            if (input.get(mid) == INT_MIN || input.get(mid) > target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }

    //Given a target integer T and an integer array A, A is sorted in ascending order first, then shifted by an arbitrary number of positions.
    //For Example, A = {3, 4, 5, 1, 2} (shifted left by 2 positions). Find the index i such that A[i] == T or return -1 if there is no such index.
    int search(vector<int> input, int target) 
    {

    }

};