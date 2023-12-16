#include <bits/stdc++.h>
int GetCardId(std::string s) {
  return std::stoi(s.substr(s.find("d ") + 1, s.find(":") - s.find("d ") - 1));
}

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
      points++;
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
  std::vector<std::string> all_lines;
  std::map<int, int> card_instances;
  while (std::getline(std::cin, line)) {
    // std::cout << "Inserted To Map: " << GetCardId(line) << ", " << 1
    //           << std::endl;
    card_instances.insert({GetCardId(line), 1});
    all_lines.push_back(line);
  }

  for (int i = 0; i < all_lines.size(); i++) {
    int curr_card_id = i + 1;
    int iterations = GetGamePoints(all_lines[i]);
    for (int j = 0; j < iterations; j++) {
      card_instances[curr_card_id + 1 + j] += 1 * card_instances[curr_card_id];
    }
  }
  int total = 0;
  for (std::pair<int, int> pair : card_instances) {
    std::cout << "Card Id: " << pair.first << ", Instances: " << pair.second
              << std::endl;
    total += pair.second;
  }

  std::cout << "Total Instances: " << total << std::endl;
}