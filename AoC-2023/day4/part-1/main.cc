#include <bits/stdc++.h>

std::string GetWinningNumbers(std::string s) {
  return s.substr(s.find(":") + 1, s.find("|") - (s.find(":") + 1));
}

std::string GetCardNumbers(std::string s) {
  return s.substr(s.find("|") + 1, s.size() - (s.find("|") + 1));
}

std::string RemoveCardNumber(std::string s) { return s.erase(0, s.find(":")); }

int GetGamePoints(const std::string& line) {
  int points = 0;
  std::string card_numbers = GetCardNumbers(line);
  std::string winning_numbers = GetWinningNumbers(line);
  // 41 48 83 86 17 | 83 86  6 31 17  9 48 53
  std::cout << line << std::endl;
  for (int i = 1; i < card_numbers.size(); i += 3) {
    std::string card_number = card_numbers.substr(i, 2);
    if (winning_numbers.find(" " + card_number + " ") != std::string::npos) {
      std::cout << "Card Number Is Winning: " << card_number << std::endl;
      if (points == 0) {
        points = 1;
      } else {
        points *= 2;
      }
    }
  }
  std::cout << "Points: " << points << std::endl;
  std::cout << std::endl;
  //   std::cout << "Card Numbers: " << GetCardNumbers(line) << std::endl;
  //   std::cout << "Winning Numbers: " << GetWinningNumbers(line) <<
  //
  return points;
}

int main() {
  std::string line;
  std::vector<int> game_points;
  while (std::getline(std::cin, line)) {
    game_points.push_back(GetGamePoints(line));
  }
  std::cout << "Total Points: "
            << std::accumulate(game_points.begin(), game_points.end(), 0)
            << std::endl;
}