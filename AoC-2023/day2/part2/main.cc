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

int GetPowerOfGame(std::string line) {
  std::cout << "Running Function" << std::endl;
  std::map<std::string, int> color_map = {
      {"red", 0}, {"green", 0}, {"blue", 0}};
  std::map<std::string, int> max_colors_required{
      {"red", 0}, {"green", 0}, {"blue", 0}};
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
      if (max_colors_required[color_count_pair.first] <
          color_count_pair.second) {
        max_colors_required[color_count_pair.first] = color_count_pair.second;
      }
    }
    color_map.clear();
  }
  std::cout << "Red: " << max_colors_required["red"]
            << " Green: " << max_colors_required["green"]
            << " Blue: " << max_colors_required["blue"] << std::endl;
  int power = max_colors_required["red"] * max_colors_required["green"] *
              max_colors_required["blue"];

  return power;
}

// 12 red cubes, 13 green cubes, and 14 blue cubes
int main() {
  // std::map<std::string, std::map<std::string, int>> game_map;
  std::vector<int> game_powers;
  std::map<std::string, int> max_possible_colors{
      {"red", 12}, {"green", 13}, {"blue", 14}};
  std::string s;
  while (std::getline(std::cin, s)) {
    // std::cout << CheckGame(s) << std::endl;
    std::cout << "Game: " << GetGameNum(s) << " with power" << GetPowerOfGame(s)
              << std::endl;
    game_powers.push_back(GetPowerOfGame(s));
  }

  int sum = 0;
  std::cout << " Game Powers : ";
  for (int i : game_powers) {
    std::cout << i << ", ";
    sum += i;
  }

  std::cout << std::endl << " sum: " << sum << std::endl;
}
