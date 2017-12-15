#include "JsonParser.h"

using namespace Esaypp::EsayJson;

JSONObject JSONParser::parse(std::string strJSON)
{
	JSONObject jsonObjRes;
	std::size_t t_beginPos = 0;
	std::size_t t_nextColonPos = std::string::npos;
	std::size_t t_nextCommaPos = std::string::npos;
	std::string t_key;
	std::string t_value;
	while ((t_nextColonPos = strJSON.find(R"(:)", t_beginPos)) != std::string::npos)
	{
		t_nextCommaPos = strJSON.find(R"(,)", t_nextColonPos + 1);
		if (t_nextCommaPos == std::string::npos)
		{
			t_nextCommaPos = strJSON.length() - 1;
		}
		std::size_t t_key_begin = strJSON.find(R"(")", t_beginPos);
		std::size_t t_key_end = strJSON.find(R"(")", t_key_begin + 1);
		if (t_key_begin != std::string::npos && t_key_end != std::string::npos
			&& t_key_begin < t_nextColonPos && t_key_end < t_nextColonPos)
		{
			t_key = strJSON.substr(t_key_begin + 1, t_key_end - t_key_begin - 1);
		}
		else
		{
			t_beginPos = t_nextCommaPos + 1;
			continue;
		}
		std::size_t t_value_begin = strJSON.find(R"(")", t_nextColonPos + 1);
		std::size_t t_value_end = strJSON.find(R"(")", t_value_begin + 1);
		if (t_value_begin != std::string::npos && t_value_end != std::string::npos)
		{
			t_value = strJSON.substr(t_value_begin + 1, t_value_end - t_value_begin - 1);
			jsonObjRes.set(t_key, JSONVariable(t_value));
		}
		else
		{
			t_value = strJSON.substr(t_nextColonPos + 1, t_nextCommaPos - t_nextColonPos - 1);
			jsonObjRes.set(t_key, JSONVariable(t_value));
		}
		t_beginPos = t_nextCommaPos + 1;
	}
	return jsonObjRes;
}