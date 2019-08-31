#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
  long curr_total = LinuxParser::Jiffies();
  long curr_active = LinuxParser::ActiveJiffies();
  float cpu_util = (curr_active - last_active_jiffies_)/(float)(curr_total - last_total_jiffies_);
  last_active_jiffies_ = curr_active;
  last_total_jiffies_ = curr_total;
  return cpu_util;
}