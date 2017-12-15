#ifndef JSONVALUE_H
#define JSONVALUE_H

#include <string>
#include "JsonException.h"

namespace Esaypp
{
    namespace EsayJson
    {
        class JSONVariable {
        public:
            // a function declaration cannot provide both a pure-specifier and a definition
            JSONVariable() = default;
            JSONVariable(const std::string& str) : _value(str)
            {
            }
            template <typename T>
            T convert() {
                try {
                    return (T)_value;
                }
                catch (const std::exception& e) {
                    throw JSONConvertException{};
                }
            }
            std::string get()
            {
                return _value;
            }

        private:
            std::string _value;
        };
    }
}

#endif // JSONVALUE_H