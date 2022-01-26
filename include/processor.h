#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
   long CurrentTotal();
   long CurrentActive();
   long CurrentIdle();
   long PrevTotal();
   long PrevIdle();

   long _total;
   long _active;
   long _idle;
};

#endif