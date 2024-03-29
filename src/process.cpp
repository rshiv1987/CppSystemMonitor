#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process (const int &pid) : pid_(pid) {}

// DONE: Return this process's ID
int Process::Pid() {
  return pid_;
}
 
// TODO: Return this process's CPU utilization
float Process::CpuUtilization(){
  return cpu_util_;
}

// Update this process's CPU utilization
void Process::Update() {
  user_ = LinuxParser::User(pid_);
  command_ = LinuxParser::Command(pid_);
  ram_= LinuxParser::Ram(pid_);
  uptime_ = LinuxParser::UpTime(pid_);
  long active_time = LinuxParser::ActiveJiffies(pid_);
  double active_time_seconds = (float)active_time / sysconf(_SC_CLK_TCK);
  if (uptime_ > 0){
    cpu_util_ = active_time_seconds/uptime_;
  }
  else {
    cpu_util_ = 0.0;
  }
}

// DONE: Return the command that generated this process
string Process::Command() {
  return command_; 
}

// DONE: Return this process's memory utilization
string Process::Ram() { 
  return ram_; 
}

// DONE: Return the user (name) that generated this process
string Process::User() { 
  return user_; 
}

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { 
  return uptime_;
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
  bool result = (cpu_util_ > a.cpu_util_);
  return result;
}