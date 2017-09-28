/**
 * Filename: BadStack.cpp
 * Class: CS3251
 *
 * @author G. Hemingway
 * Description: This stack is just not right
 */

#include "BadStack.h"

Stack::Stack(uint32_t size) : stackTop(0), size(size), stack(new T[size]) {}

Stack::Stack(const Stack &inStack)
    : stackTop(inStack.stackTop), size(inStack.size),
      stack(new T[inStack.size]) {
  for (uint32_t i = 0; i < inStack.stackTop - 1; i++) {
    stack[i] = inStack.stack[i];
  }
}

Stack::~Stack() { delete[] stack; }

Stack &Stack::operator=(const Stack &inStack) {
  if (this != &inStack) {
    auto *temp_stack = new T[inStack.size];
    delete[] stack;
    for (uint32_t i = 0; i < inStack.stackTop - 1; i++) {
      temp_stack[i] = inStack.stack[i];
    }
    stack = temp_stack;
    stackTop = inStack.stackTop;
    size = inStack.size;
  }
  return *this;
}

void Stack::push(const T &item) {
  stack[stackTop] = item;
  stackTop++;
}

T Stack::pop() { return stack[--stackTop]; }

T Stack::top() {
  T item = stack[stackTop - 1];
  return item;
}

bool Stack::isEmpty() const { return stackTop == 0; }

bool Stack::isFull() const { return stackTop >= size; }

uint32_t Stack::count() const { return stackTop; }
