#include <zonotope.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

elina_interval_t** read_interval(std::string filename) {
  std::vector<double> low;
  std::vector<double> upp;
  std::ifstream in(filename.c_str());
  std::string line;
  while (getline(in, line)) {
    std::istringstream iss(line);
    double l, u;
    iss.get();
    iss >> l;
    iss.get();
    iss.get();
    iss >> u;
    low.push_back(l);
    upp.push_back(u);
  }

  elina_interval_t** itv = (elina_interval_t**) malloc(low.size() * sizeof(elina_interval_t*));

  for (int i = 0; i < low.size(); i++) {
    itv[i] = elina_interval_alloc();
    elina_interval_set_double(itv[i], low[i], upp[i]);
  }

  return itv;
}

int main() {
  elina_interval_t** itv = read_interval("interval.txt");
}
