#include <bits/stdc++.h>
std::string GetGameNum(std::string s) { return s.substr(5, s.find(":") - 5); }

std::vector<std::string> GetColorsShown(std::string s) {
  std::vector<std::string> revealed_colors;
  s.erase(0, s.find(":") + 1);
  std::cout << "Current line: " << s << std::endl << std::endl;
  while (s.find(";") != std::string::npos || s.size() != 0) {
    if (s.find(";") != std::string::npos) {
      revealed_colors.push_back(s.substr(0, s.find(";")));
      s.erase(0, s.find(";") + 1);
    } else {
      revealed_colors.push_back(s.substr(0, s.size()));
      s.erase(0, s.size());
    }
    // std::cout << "Current line: " << s << std::endl;
  }
  return revealed_colors;
}

bool CheckGame(std::string line) {
  std::map<std::string, int> color_map = {
      {"red", 0}, {"green", 0}, {"blue", 0}};
  std::map<std::string, int> possible_colors{
      {"red", 12}, {"green", 13}, {"blue", 14}};
  std::vector<std::string> current_game_revealed_colors = GetColorsShown(line);
  if (current_game_revealed_colors.empty()) {
    return false;
  }
  for (std::string revealed_pairs : current_game_revealed_colors) {
    std::cout << "current pair:" << revealed_pairs << std::endl;
    while (revealed_pairs.find("red") != std::string::npos ||
           revealed_pairs.find("green") != std::string::npos ||
           revealed_pairs.find("blue") != std::string::npos) {
      if (revealed_pairs.find("red") >= 3 &&
          (revealed_pairs.find("red") < revealed_pairs.find(",") ||
           revealed_pairs.find(",") == std::string::npos) &&
          revealed_pairs.find("red") != std::string::npos) {
        color_map["red"] +=
            std::stoi(revealed_pairs.substr(1, revealed_pairs.find("red") - 1));
        std::cout << "Added red: " << color_map["red"] << std::endl;
        if (revealed_pairs.find(",") != std::string::npos) {
          revealed_pairs.erase(0, revealed_pairs.find(",") + 1);
        } else {
          revealed_pairs.erase(0, revealed_pairs.size());
        }
      } else if (revealed_pairs.find("green") >= 3 &&
                 (revealed_pairs.find("green") < revealed_pairs.find(",") ||
                  revealed_pairs.find(",") == std::string::npos) &&
                 revealed_pairs.find("green") != std::string::npos) {
        color_map["green"] += std::stoi(
            revealed_pairs.substr(1, revealed_pairs.find("green") - 1));
        std::cout << "Added green: " << color_map["green"] << std::endl;
        if (revealed_pairs.find(",") != std::string::npos) {
          revealed_pairs.erase(0, revealed_pairs.find(",") + 1);
        } else {
          revealed_pairs.erase(0, revealed_pairs.size());
        }
      } else if (revealed_pairs.find("blue") >= 3 &&
                 (revealed_pairs.find("blue") < revealed_pairs.find(",") ||
                  revealed_pairs.find(",") == std::string::npos) &&
                 revealed_pairs.find("blue") != std::string::npos) {
        color_map["blue"] += std::stoi(
            revealed_pairs.substr(1, revealed_pairs.find("blue") - 1));
        std::cout << "Added blue: " << color_map["blue"] << std::endl;
        if (revealed_pairs.find(",") != std::string::npos) {
          revealed_pairs.erase(0, revealed_pairs.find(",") + 1);
        } else {
          revealed_pairs.erase(0, revealed_pairs.size());
        }
      }
      // std::cout << "current pair:" << revealed_pairs << std::endl;
    }
    for (std::pair<std::string, int> color_count_pair : color_map) {
      std::cout << "color: " << color_count_pair.first
                << " count: " << color_count_pair.second << std::endl;
      std::cout << "possible color: " << possible_colors[color_count_pair.first]
                << std::endl;
      if (color_count_pair.second > possible_colors[color_count_pair.first]) {
        return false;
      }
    }
    color_map.clear();
  }

  return true;
}
// 12 red cubes, 13 green cubes, and 14 blue cubes
int main() {
  // std::map<std::string, std::map<std::string, int>> game_map;
  std::vector<int> possible_game_num;
  std::map<std::string, int> possible_colors{
      {"red", 12}, {"green", 13}, {"blue", 14}};
  std::string s;
  while (std::getline(std::cin, s)) {
    // std::cout << CheckGame(s) << std::endl;
    std::cout << "Game: " << GetGameNum(s) << std::endl;
    if (CheckGame(s)) {
      std::cout << std::endl;
      possible_game_num.push_back(std::stoi(GetGameNum(s)));
    } else {
      std::cout << " is not possible" << std::endl;
    }
  }

  int sum = 0;
  std::cout << " Possible Games : ";
  for (int i : possible_game_num) {
    std::cout << i << ", ";
    sum += i;
  }

  std::cout << std::endl << " sum: " << sum << std::endl;
}
