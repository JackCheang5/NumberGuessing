#ifndef NUMBERGUESSING_NUMBERGUESS_H
#define NUMBERGUESSING_NUMBERGUESS_H

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <string>
#include <time.h>
#include <vector>

class NumberGuess {
public:
  NumberGuess();
  const int GetGuessNo();
  const int GetTriedTimes();
  const std::string Guess(const std::string);

private:
  int tried_times_{0};
  std::vector<int> guess_no_;
};

#endif