#include "EasyLogger.h"

using namespace Easypp;

EasyLogger::EasyLogger()
{
}

EasyLogger::~EasyLogger()
{
	try
	{
		this->m_logFile.close();
	}
	catch (const std::exception&)
	{

	}
}

bool EasyLogger::Init(const std::string& log_path)
{
	try
	{
		if (!this->m_logFile.is_open())
		{
			this->m_logFile.open(log_path, std::ios::ate | std::ios::out);
		}
		if (!this->m_logFile.is_open())
		{
			return false;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
	return true;
}

void EasyLogger::debug(const std::string& msg)
{
	try
	{
		if (this->m_logFile.is_open())
		{
			this->m_logFile << msg << '\n';
			this->m_logFile.flush();
		}
	}
	catch (const std::exception&)
	{

	}
}

