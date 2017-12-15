#ifndef JSONEXCEPTION_H
#define JSONEXCEPTION_H

#include <exception>
#include <string>

namespace Esaypp
{
    namespace EsayJson
    {
        class JsonException : public std::exception
        {
        public:
            JsonException() : std::exception()
            {
            }

            JsonException(std::string err) : std::exception(), m_msg(err)
            {
            }

        private:
            std::string m_msg;
        };

        class JSONConvertException : public JsonException
        {
        public:
            JSONConvertException() : JsonException("JSON Convert Error!")
            {
            }
        };

        class JSONGetException : public JsonException
        {
        public:
            JSONGetException(std::string key) : JsonException("JSON Key: " + key + " Get Error!")
            {
            }
        };
    }
}

#endif // JSONEXCEPTION_H