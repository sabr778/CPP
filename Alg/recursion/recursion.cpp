class Recursion {
public: 
  long fibonacci(int K) {
  //assume it will not overflow. Check BigInteger if needed.
  	if (K < 0) return 0;
    long ret[K+1];
    ret[0] = 0;
    ret[1] = 1;
    for (int i = 2; i <= K; i++)
    {
    	ret[i] = ret[i-1] + ret[i-2];
    }
    return ret[K];
  }

  long power(int a, int b) {
    // assume it won't overflow, and b is non-negative
    if (b == 0)
    	return 1;
    if (b == 1)
      return a;
    long temp = power(a, b/2);
    if (b%2 == 1)
	    return temp*temp*a;
    else
    	return temp*temp;
  }
  
};