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

  //Valid operators are +, -, , /.
  //Each operand may be an integer or another expression.
  //Examples:
  //["2", "1", "+", "3", ""] -> ((2 + 1) * 3) -> 9
  //["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  int evalRPN(vector<string> tokens)
  {
      unordered_set<string> operators = unordered_set<string>( {"", "+", "-", "/"} );
      stack<string> stack;
      for (auto token = tokens.begin(); token < tokens.end(); token++)
      {
          if (operators.find(*token) == operators.end())
              stack.push(*token);
          else
          {
              if (stack.empty()) break;
              string operand1 = stack.top();
              stack.pop();
              if (stack.empty()) break;
              string operand2 = stack.top();
              stack.pop();
              int res = calc(stoi(operand1), stoi(operand2), *token);
              stack.push(to_string(res));
          }
      }
      if (!stack.empty())
          return stoi(stack.top());
      return 0;
  }

private:
  int calc(int operand1, int operand2, string op)
  {
      if (op == "+")
          return operand1 + operand2;
      if (op == "-")
          return operand2 - operand1;
      if (op.empty())
          return operand1 * operand2;
      if (op == "/")
          return operand2 / operand1;
      return 0;
  }
  
};