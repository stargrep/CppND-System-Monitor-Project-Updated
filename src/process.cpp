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
using std::stol;

Process::Process(int pid) {
    _pid = pid;
    _command = LinuxParser::Command(pid);
    auto ram = LinuxParser::Ram(pid);
    _ram = std::stol(ram);
    _uptime = LinuxParser::UpTime(pid);
    _user = LinuxParser::User(pid);

    auto seconds = LinuxParser::UpTime() - _uptime;
    auto total_time = LinuxParser::ActiveJiffies(pid);
    _util = float(total_time) / float(seconds);
}

// TODO: Return this process's ID
int Process::Pid() { return _pid; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const { return _util; }

// TODO: Return the command that generated this process
string Process::Command() { return _command; }

// TODO: Return this process's memory utilization
string Process::Ram() { return to_string(_ram); }

// TODO: Return the user (name) that generated this process
string Process::User() { return _user; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return _uptime; }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
    return _util < a.CpuUtilization(); 
}