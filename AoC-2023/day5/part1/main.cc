#include <bits/stdc++.h>
// Seeds already Checked:
// 104847962 3583832 1212568077 114894281 3890048781 333451605
template <typename T>
void DisplayVector(std::vector<T> v, std::string vector_name) {
  std::cout << "Displaying " << vector_name << ": ";
  for (T i : v) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
}

void DisplayMap(std::unordered_map<std::string, std::vector<std::string>> m) {
  for (auto i : m) {
    std::cout << "Displaying " << i.first << std::endl;
    DisplayVector(i.second, "vector");
  }
}

std::vector<long long> getSeeds(std::string s) {
  std::vector<long long> seeds;
  s.erase(0, s.find(":") + 1);
  std::stringstream ss(s);
  std::string number;
  while (ss >> number) {
    seeds.push_back(std::stoll(number));
  }
  return seeds;
}

long long SeedConversionDestination(std::vector<std::string> conversions,
                                    long long seed) {
  long long destination_range_start;
  long long source_range_start;
  long long range_length;
  std::string number;
  for (std::string s : conversions) {
    std::stringstream ss(s);
    ss >> number;
    destination_range_start = std::stoll(number);
    ss >> number;
    source_range_start = std::stoll(number);
    ss >> number;
    range_length = std::stoll(number);
    // std::cout << "destination_range_start: " << destination_range_start
    //           << std::endl;
    // std::cout << "source_range_start: " << source_range_start << std::endl;
    // std::cout << "range_length: " << range_length << std::endl;
    // std::cout << "seed: " << seed << std::endl;
    if (seed >= source_range_start &&
        seed < source_range_start + range_length) {
      //   std::cout << "Seed is withing source range returning: "
      //             << destination_range_start + (seed - source_range_start)
      //             << std::endl;
      return destination_range_start + (seed - source_range_start);
    }
  }
  return seed;
}

int main() {
  std::vector<long long> seeds_;
  std::string line;
  std::string current_map;
  std::unordered_map<std::string, std::vector<std::string>> conversion_map;
  while (std::getline(std::cin, line)) {
    if (line.empty()) {
      continue;
    }
    // std::cout << line << std::endl;
    if (seeds_.empty()) {
      seeds_ = getSeeds(line);
    } else if (line.find(":") != std::string::npos) {
      current_map = line;
    } else {
      conversion_map[current_map].push_back(line);
    }
  }
  std::vector<std::string> conversion_order = {
      "seed-to-soil map:",         "soil-to-fertilizer map:",
      "fertilizer-to-water map:",  "water-to-light map:",
      "light-to-temperature map:", "temperature-to-humidity map:",
      "humidity-to-location map:"};
  for (int i = 0; i < seeds_.size(); i++) {
    for (std::string s : conversion_order) {
      seeds_[i] = SeedConversionDestination(conversion_map[s], seeds_[i]);
    }
  }
  // RESULTS
  DisplayVector(seeds_, "results");
  // Use min_element to get an iterator pointing to the smallest element
  auto smallest = std::min_element(seeds_.begin(), seeds_.end());

  // Dereference the iterator to get the smallest element
  int smallest_number = *smallest;
  std::cout << "Smallest seed: " << smallest_number << std::endl;
  return 0;
}