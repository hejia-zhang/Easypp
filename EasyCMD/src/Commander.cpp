//
// Created by Hejia Zhang on 2017/12/16.
//

#include "Commander.h"
#include <cstdlib>

using namespace Easypp;
using namespace EasyCMD;

bool Commander::Init()
{
    if (system(nullptr))
    {
        return true;
    }
    else return false;
}

EasyErrCode::ERR_CODE Commander::SyncSendCMD()
{

}

EasyErrCode::ERR_CODE Commander::AsyncSendCMD()
{

}
