#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>

class Solution
{
public:
  // 判断操作符优先级
  int precedence(const std::string &op)
  {
    if (op == "+" || op == "-")
    {
      return 1;
    }
    if (op == "*" || op == "/")
    {
      return 2;
    }
    return 0;
  }

  std::vector<std::string> infixToPostfix(const std::vector<std::string> &tokens)
  {
    std::stack<std::string> opStack; // 操作符栈
    std::vector<std::string> output; // 输出的后缀表达式

    for (const auto &token : tokens)
    {
      if (std::isdigit(token[0]))
      {
        output.push_back(token); // 如果是数字，加入输出
      }
      else if (token == "(")
      {
        opStack.push(token); // 左括号入栈
      }
      else if (token == ")")
      {
        // 遇到右括号，直到左括号为止
        while (!opStack.empty() && opStack.top() != "(")
        {
          output.push_back(opStack.top());
          opStack.pop();
        }
        opStack.pop(); // 弹出左括号
      }
      else
      { // 如果是操作符
        while (!opStack.empty() && precedence(opStack.top()) >= precedence(token))
        {
          output.push_back(opStack.top());
          opStack.pop();
        }
        opStack.push(token); // 当前操作符入栈
      }
    }

    // 将栈中剩余的操作符加入输出
    while (!opStack.empty())
    {
      output.push_back(opStack.top());
      opStack.pop();
    }

    return output; // 返回转换后的后缀表达式
  }
};

int main()
{
  Solution solution;
  std::vector<std::string> infix = {"4", "+", "5", "*", "6", "*", "7"};
  std::vector<std::string> postfix = solution.infixToPostfix(infix);

  std::cout << "后缀表达式: ";
  for (const auto &token : postfix)
  {
    std::cout << token << " ";
  }
  std::cout << std::endl;

  return 0;
}