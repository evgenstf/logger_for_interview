#include "logger.h"

namespace logger {

void Logger::print_log(Log log) {
  print_log_internal(log);
  ++log_level_messages_count_[log.level];
}

void Logger::print_statistics() {
  for (
      auto it = log_level_messages_count_.begin();
      it != log_level_messages_count_.end();
      ++it
  ) {
    std::clog << "log_level: " << it->first << " messages_count: " << it->second << '\n';
  }
}

void Logger::print_log_internal(Log log) {
  std::clog << log.level << " :: " << log.message << std::endl;
  std::clog.flush();
}

void FileLogger::print_log_internal(Log log) {
  file_stream_ << log.level << " :: " << log.message << '\n';
  file_stream_.flush();
}

}  // namespace logger
