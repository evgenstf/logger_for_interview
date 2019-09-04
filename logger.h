#pragma once
#include "log_level_defines.h"
#include <atomic>
#include <iostream>
#include <string>
#include <queue>
#include <condition_variable>
#include <thread>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;

namespace logger {

struct Log {
  string level;
  string message;
};

class Logger {
public:
  void print_log(Log log);
  void print_statistics();

protected:
  virtual void print_log_internal(Log log);

  std::map<std::string, int> log_level_messages_count_;
};

class FileLogger : public Logger {
public:
  FileLogger(std::string file_name):
      file_name_(file_name), file_stream_(file_name) {}

private:
  void print_log_internal(Log log);

  std::string file_name_;
  std::ofstream file_stream_;
};

static Logger ___logger___;


}  // namespace logger
