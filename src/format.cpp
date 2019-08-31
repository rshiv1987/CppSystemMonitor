#include <string>

#include "format.h"

using std::string;
using std::to_string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
  int hr, min, sec;
  string time {};
  hr = seconds/3600;
  sec = (seconds % 3600);
  min = sec / 60;
  sec = sec % 60;
  time += ToString(hr) + ':' + ToString(min) + ':' + ToString(sec);
  return time;
}

string Format::ToString (int t){
  return (t < 10) ? ('0' + to_string(t)) : to_string(t);
}