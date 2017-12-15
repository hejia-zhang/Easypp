#include "JsonObject.h"

using namespace Esaypp::EsayJson;

std::string JSONObject::stringfy()
{
	std::string res = "{";
	for (auto& val : _memory)
	{
		res += (R"(")" + val.first + R"(")" + ":" + R"(")" + val.second.get() + R"(")" + ",");
	}
	res.replace(res.length() - 1, 1, "}");
	return res;
}