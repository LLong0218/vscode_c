#include <iostream>
#include <string>
#include <vector>
#include <stack>

int prior(std::string now)
{
  if (now == "+" || now == "-")
  {
    return 1;
  }
  if (now == "*" || now == "/")
  {
    return 2;
  }
  return 0;
}

std::vector<std::string> infixtopostfix(std::vector<std::string> &tokens)
{
  // 准备工作：需要的两个栈，一个是数字栈，一个是操作符栈
  std::vector<std::string> output;
  std::stack<std::string> opstack;

  // 规则：
  for (const auto ch : tokens)
  {
    // 1. 数字直接入输出序列
    if (std::isdigit(ch[0]))
    {
      output.push_back(ch);
    }
    // 2. 如果碰到操作符
    // 2.1 是加减乘除的话判断优先级
    // 2.2 是左括号入栈
    // 2.3 是右括号，输出到左括号为止
    else if (ch == "(")
    {
      opstack.push(ch);
    }
    else if (ch == ")")
    {
      while (!opstack.empty() && opstack.top() != "(")
      {
        // 哦哦所以其实左括号这种东西是不会输出滴
        auto next = opstack.top();
        output.push_back(next);
        opstack.pop();
      }
      // 弹出左括号
      opstack.pop();
    }
    else
    {
      // 如果栈内的操作符优先级比将要放入的要高，就先输出高优先级的
      while (!opstack.empty() && prior(opstack.top()) >= prior(ch))
      {
        output.push_back(opstack.top());
        opstack.pop();
      }
      // 再把目标操作符放入栈
      opstack.push(ch);
    }
  }
  // 如果到结束还有操作符没出栈就自动都出栈
  while (!opstack.empty())
  {
    output.push_back(opstack.top());
    opstack.pop();
  }
  // 返回结果
  return output;
}

int main()
{
  std::vector<std::string> infix = {"4", "+", "5", "*", "6", "*", "7"};
  std::vector<std::string> postfix = infixtopostfix(infix);

  std::cout << "后缀表达式: ";
  for (const auto &token : postfix)
  {
    std::cout << token << " ";
  }
  std::cout << std::endl;

  return 0;
}