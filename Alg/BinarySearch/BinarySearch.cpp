class BinarySearch
{
public:
	int classic(vector<int> input, int target) 
	{
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


  	int firstOccur(vector<int> array, int target) 
  	{
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

};