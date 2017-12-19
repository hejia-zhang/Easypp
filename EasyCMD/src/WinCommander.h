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

            bool Init();

            int SendCommand(const std::string& cmd);

            bool EasyCreatePipe();

            bool EasyCreateProcess();

        private:
            void *m_pPipeWrite;
            void *m_pPipeRead;
        };
    }
}
#endif