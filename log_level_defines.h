#define TRACE(message) {\
  std::stringstream log_stream;\
  log_stream << message;\
  ___logger___.print_log({"TRACE", log_stream.str()});\
}

#define DEBUG(message) {\
  std::stringstream log_stream;\
  log_stream << message;\
  ___logger___.print_log({"DEBUG", log_stream.str()});\
}

#define INFO(message) {\
  std::stringstream log_stream;\
  log_stream << message;\
  ___logger___.print_log({"INFO", log_stream.str()});\
}

#define WARNING(message) {\
  std::stringstream log_stream;\
  log_stream << message;\
  ___logger___.print_log({"WARNING", log_stream.str()});\
}

#define ERROR(message) {\
  std::stringstream log_stream;\
  log_stream << message;\
  ___logger___.print_log({"ERROR", log_stream.str()});\
}

#define FATAL(message) {\
  std::stringstream log_stream;\
  log_stream << message;\
  ___logger___.print_log({"FATAL", log_stream.str()});\
}
