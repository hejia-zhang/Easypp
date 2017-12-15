#ifndef EASYLOGGER_H
#define EASYLOGGER_H
#include <string>
#include <fstream>

namespace Easypp
{
    class EasyLogger
    {
    public:
        EasyLogger();

        ~EasyLogger();

        bool Init(const std::string& log_path);

        void debug(const std::string& msg);

    private:
        std::ofstream m_logFile;
    };
}
#endif

