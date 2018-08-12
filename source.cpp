#include "NumberGuess.h"
#include <iostream>

int main() {
  std::string input;
  std::string result;
  NumberGuess A = NumberGuess();
  // std::cout << A.GetGuessNo() << '\n'; // for debug
  while (true) {
    if (A.GetTriedTimes() > 7) {
      std::cout << "Lose\n";
      break;
    }
    std::cout << "Enter your guess:\n>>";
    std::cin >> input;
    try {
      result = A.Guess(input);
    } catch (char const *error) {
      std::cout << error << '\n';
      system("pause");
      continue;
    }
    if (result == "4A0B") {
      std::cout << "Win\n";
      break;
    }
    std::cout << "The " << A.GetTriedTimes() << "th guessing: " << result
              << '\n';
  }
  system("pause");
  return 0;
}