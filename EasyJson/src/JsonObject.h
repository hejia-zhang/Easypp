#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "JsonVariable.h"

namespace Esaypp
{
	namespace EsayJson
    {
        class JSONObject
        {
        public:
            bool has(std::string key)
            {
                if (_memory.find(key) == _memory.end())
                {
                    return false;
                }
                return true;
            }

            void set(std::string key, JSONVariable value)
            {
                _memory[key] = value;
            }

            std::string stringfy();

            template <typename T>
            T get(std::string key)
            {
                JSONVariable t_val = _memory[key];
                T t_res;
                try
                {
                    t_res = t_val.convert<T>();
                    return t_res;
                }
                catch (const JSONConvertException& err)
                {
                    throw JSONGetException(key);
                }
            }

        private:
            std::map<std::string, JSONVariable> _memory; // internal memory
        };
    }
}

#endif // JSONOBJECT_H