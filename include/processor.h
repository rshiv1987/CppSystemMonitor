#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  long last_total_jiffies_ = 0; // stores the last value of total_jiffies
  long last_active_jiffies_ = 0; // stores the last value of active_jiffies
};

#endif