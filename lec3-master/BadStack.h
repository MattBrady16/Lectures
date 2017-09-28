/**
 * Filename: BadStack.h
 * Class: CS3251
 *
 * @author G. Hemingway
 * Description: This stack is just not right
 */

#ifndef BADSTACK_H
#define BADSTACK_H

// This header defines "uint32_t"
#include <cstdint>
#include <cstdlib>

// Type of Stack element
typedef int T;

class Stack {
public:
  /* Constructors */
  Stack(uint32_t size);
  Stack(const Stack &inStack);
  /* Destructor */
  ~Stack();

  Stack &operator=(const Stack &);

  void push(const T &item);
  T pop();
  T top();
  bool isEmpty() const;
  bool isFull() const;
  uint32_t count() const;

private:
  uint32_t stackTop, size;
  T *stack;
};

#endif
