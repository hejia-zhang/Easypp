//
// Created by Hejia Zhang on 2017/12/16.
//

#ifndef EASYPP_COMMANDER_H
#define EASYPP_COMMANDER_H

#include "EasyErrCode.h"

namespace Easypp
{
    namespace EasyCMD
    {
        class Commander
        {
        public:
            Commander()
            {

            }

            virtual bool Init();

            virtual EasyErrCode::ERR_CODE SyncSendCMD();

            virtual EasyErrCode::ERR_CODE AsyncSendCMD();
        };
    }
}

#endif //EASYPP_COMMANDER_H
