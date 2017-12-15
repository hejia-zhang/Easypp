#ifndef WINCOMMANDER_H
#define WINCOMMANDER_H

#include <string>

namespace Easypp
{
    namespace EasyCMD
    {
        class WinCommander
        {
        public:
            WinCommander()
            {
            }

            int SendCommand(const std::string& cmd);
        };
    }
}
#endif