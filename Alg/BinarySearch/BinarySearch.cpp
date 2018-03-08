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

};