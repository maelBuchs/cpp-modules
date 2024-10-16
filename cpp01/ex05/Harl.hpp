#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

typedef std::string str;

class Harl {
  public:
    void complain(str level);
    Harl(void);
    ~Harl(void);

  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif