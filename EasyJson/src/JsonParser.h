#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>
#include "JsonObject.h"

namespace Esaypp
{
    namespace EsayJson
    {
        class JSONParser
        {
        public:
            JSONObject parse(std::string strJSON);
        };
    }
}

#endif