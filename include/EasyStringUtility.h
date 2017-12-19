//
// Created by Hejia Zhang on 2017/12/19.
//

#ifndef EASYPP_EASYSTRINGUTILITY_H
#define EASYPP_EASYSTRINGUTILITY_H

#include <string>

namespace Easypp
{
    namespace EasyStringUtility
    {
        void ReplaceAllSubstr(std::string& srcstr, const std::string& oldsubstr, const std::string& newsubstr)
        {
            int t_nPos = 0;
            while ((t_nPos = srcstr.find(oldsubstr, nPos) != srcstr.npos))
            {
                srcstr.replace(nPos, oldsubstr.length(), newsubstr);
                t_nPos += newsubstr.length();
            }
        }
    }
}

#endif //EASYPP_EASYSTRINGUTILITY_H
