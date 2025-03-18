#pragma once

#include <deque>
#include <exception>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

typedef std::pair<int, int>  intPair;
typedef std::vector<intPair> pairVec;

class PmergeMe {
  public:
    PmergeMe(char **input);
    ~PmergeMe();

    std::deque<int>  getDequeData() const { return _dequeData; }
    std::vector<int> getVectorData() const { return _vectorData; }

    class InvalidInput : public std::exception {
      public:
        const char *what() const throw();
    };
    void processData();

  private:
    std::deque<int>  _dequeData;
    std::vector<int> _vectorData;

    void                    parseInput(char **input);
    template <typename T> T merge(T mins, T maxs) {
        T                          result;
        typename T::const_iterator itMax = maxs.begin();
        typename T::const_iterator itMin = mins.begin();

        while (itMax != maxs.end() && itMin != mins.end()) {
            if (*itMin < *itMax) {
                result.push_back(*itMin);
                ++itMin;
            } else {
                result.push_back(*itMax);
                ++itMax;
            }
        }

        while (itMin != mins.end()) {
            result.push_back(*itMin);
            ++itMin;
        }
        while (itMax != maxs.end()) {
            result.push_back(*itMax);
            ++itMax;
        }

        return result;
    }

    template <typename T> T fordJhonson(T list, int depth) {
        int last = -1;
        if (list.size() <= 1)
            return list;

        pairVec pairs;
        for (unsigned long i = 0; i < list.size(); i += 2) {
            if (i + 1 < list.size())
                pairs.push_back(std::pair<int, int>(std::max(list[i], list[i + 1]),
                                                    std::min(list[i], list[i + 1])));
            else {
                last = list[i];
            }
        }

        T maxList, minList;

        for (pairVec::iterator it = pairs.begin(); it != pairs.end(); it++) {
            maxList.push_back(it->first);
            minList.push_back(it->second);
        }
        if (last != -1)
            minList.push_back(last);

        T sortedMax = fordJhonson(maxList, depth + 1);
        T sortedMin = fordJhonson(minList, depth + 1);

        T result = merge(sortedMin, sortedMax);
        return result;
    }

    template <typename T> void printContainer(T container) {
        for (typename T::iterator it = container.begin(); it != container.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};

std::ostream &operator<<(std::ostream &os, const PmergeMe &pm);