class Iteration {
public:
  	//Synopsis: Given an array A[0]...A[n-1] of integers, find out the length of the longest ascending subsequence.
  	//Assumptions: A is not null
  	int longest(vector<int> array)
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
};