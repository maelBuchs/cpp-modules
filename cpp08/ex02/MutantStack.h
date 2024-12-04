#include <deque>
#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {

public:
  MutantStack(){};
  ~MutantStack(){};
  typedef typename std::deque<T>::iterator iterator;
  typedef typename std::deque<T>::const_iterator const_iterator;
  typedef typename std::deque<T>::reverse_iterator reverse_iterator;
  typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

  int empty() { return _stack.empty(); };
  int size() { return _stack.size(); };
  void push(T n) { _stack.push_front(n); };
  void pop() { _stack.pop_front(); };
  T top() { return _stack.front(); };
  
  iterator end() { return _stack.end(); };
  const_iterator end() const { return _stack.end(); };
  iterator begin() { return _stack.begin(); };
  const_iterator begin() const { return _stack.begin(); };
  reverse_iterator rend() { return _stack.rend(); };
  const_reverse_iterator rend() const { return _stack.rend(); };
  reverse_iterator rbegin() { return _stack.rbegin(); };
  const_reverse_iterator rbegin() const { return _stack.rbegin(); };

private:
  std::deque<T> _stack;
};
