/**
 * Filename: StackErrors.cpp
 * Class: CS3251
 *
 * @author Graham Hemingway
 * Description: Use this file to explore the debugger a bit
 */

#include "BadStack.h"
#include <iostream>

int main() {
  const uint32_t stack1Size = 1;
  const uint32_t stack2Size = 100;
  Stack stack1(stack1Size), stack2(stack2Size);

  // Nothing suspect here...just carry on
  stack1.push(473);
  std::cout << stack1.top() << std::endl;

  // Use the debugger to explore what values are in stack2
  for (uint32_t i = 0; i < stack2Size; ++i) {
    stack2.push(i * 2);
  }

  // This is fine right?
  for (uint32_t i = 0; i < stack2Size; ++i) {
    stack1.push(-1);
  }

  // Does this ever print?
  if (!stack1.isEmpty() && !stack1.isFull()) {
    std::cout << stack1.pop() << std::endl;
  }

  // Is stack1 correct now?
  stack1 = stack2;
  std::cout << "Stack 1 is: " << stack1.count() << " deep." << std::endl;

  // Let's double check all our values...
  for (int i = stack2Size - 1; i >= 0; --i) {
    int a = stack1.pop();
    int b = stack2.pop();
    // std::cout << b << std::endl;
    if (a != b || b != i * 2) {
      std::cout << "What the duck: " << a << " : " << b << " : " << i
                << std::endl;
    }
  }

  // Is everything going to get cleaned up OK?
  return 0;
}
