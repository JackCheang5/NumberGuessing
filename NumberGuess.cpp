#include "NumberGuess.h"

bool GenerateRepeated(const std::vector<int> array, const int no);
bool IsNumber(const std::string &input);
bool InputRepeated(std::string s);

NumberGuess::NumberGuess() {
  srand(time(NULL));
  while (guess_no_.size() < 4) {
    int random_no = rand() % 10;
    if (!GenerateRepeated(guess_no_, random_no))
      guess_no_.push_back(random_no);
  }
}

const int NumberGuess::GetGuessNo() {
  int guess_no = 1000 * guess_no_[0] + 100 * guess_no_[1] + 10 * guess_no_[2] +
                 guess_no_[3];
  return guess_no;
}

const int NumberGuess::GetTriedTimes() { return tried_times_; }

const std::string NumberGuess::Guess(const std::string guessing_no) {
  // expections handling
  if (!IsNumber(guessing_no))
    throw "Not a number";
  if (guessing_no.size() != 4)
    throw "Invalid length";
  if (InputRepeated(guessing_no))
    throw "Repeated numbers";
  // checking the number
  tried_times_++;
  std::vector<int> input_no;
  for (auto i = 0; i < guessing_no.size(); ++i)
    input_no.push_back(std::stoi(guessing_no.substr(i, 1)));
  int a{0}, b{0};
  for (auto i : input_no) // determination of B
    for (auto j : guess_no_)
      if (i == j)
        b++;
  for (auto i = 0; i < input_no.size(); ++i) {
    if (input_no[i] == guess_no_[i]) {
      a++;
      b--;
    }
  }
  std::string result = std::to_string(a) + 'A' + std::to_string(b) + 'B';
  return result;
}

bool GenerateRepeated(const std::vector<int> array, const int no) {
  for (auto x : array)
    if (no == x)
      return true;
  return false;
}

bool IsNumber(const std::string &s) {
  return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) {
                         return !std::isdigit(c);
                       }) == s.end();
}

bool InputRepeated(std::string input_no) {
  std::sort(input_no.begin(), input_no.end());
  for (auto i = 0; i < 3; ++i)
    if (input_no[i] == input_no[i + 1])
      return true;
  return false;
}
