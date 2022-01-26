#ifndef PROCESS_H
#define PROCESS_H

#include <string>

using std::string;
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid);
  int Pid();                               // TODO: See src/process.cpp
  string User();                      // TODO: See src/process.cpp
  string Command();                   // TODO: See src/process.cpp
  float CpuUtilization() const;                  // TODO: See src/process.cpp
  string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp

  // TODO: Declare any necessary private members
 private:
  int _pid;
  long _ram;
  long _uptime;
  float _util;
  string _command;
  string _user;
  
};

#endif