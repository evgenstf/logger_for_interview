#include "logger.h"
#include <iostream>
#include <vector>

using namespace logger;

int main(int arguments_count, char* arguments[]) {
  TRACE("count of rabbits " << 5);
  DEBUG("the ship successfully docked");
  INFO("a paper airplane flew out the window");
  WARNING("bitcoin fell");
  ERROR("wrong pyramid volume: " << -25);
  FATAL("the meteorite is approaching");

  std::vector<Logger*> loggers;
  for (int i = 0; i < 10; ++i) {
    loggers.push_back(new FileLogger("logs_" + std::to_string(i) + ".txt"));
  }
  for (int i = 0; i < 100; ++i) {
    loggers[i % 10]->print_log({"INFO", "sheep #" + std::to_string(i)});
  }
  for (int i = 0; i < 10; ++i) {
    loggers[i]->print_statistics();
    delete loggers[i];
  }
  return 0;
}
