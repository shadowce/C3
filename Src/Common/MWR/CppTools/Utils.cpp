#include "StdAfx.h"
#include "Utils.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool MWR::Utils::IsProcess64bit()
{
#if defined(_WIN64)
	return true;
#elif defined(_WIN32)
	return false;
#endif
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string MWR::Utils::GenerateRandomString(size_t size)
{
	static const std::string charset = OBF("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<int> uni(0, static_cast<int>(charset.size() - 1));

	std::string randomString;
	randomString.resize(size);
	for (auto& e : randomString)
		e = charset[uni(gen)];

	return randomString;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int32_t MWR::Utils::TimeSinceEpoch()
{
	return static_cast<int32_t>(std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now()).time_since_epoch().count());
}