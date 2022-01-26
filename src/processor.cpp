#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
    auto util = float((CurrentTotal() - CurrentIdle()) - (PrevTotal() - PrevIdle())) / 
                float(CurrentTotal() - CurrentIdle());
    _total = CurrentTotal();
    _active = CurrentActive();
    _idle = CurrentIdle();
    return util;
}

long Processor::CurrentTotal() { return LinuxParser::Jiffies(); }

long Processor::CurrentActive() { return LinuxParser::ActiveJiffies(); }

long Processor::CurrentIdle() { return LinuxParser::IdleJiffies(); }

long Processor::PrevTotal() { return _total; }

long Processor::PrevIdle() { return _idle; }