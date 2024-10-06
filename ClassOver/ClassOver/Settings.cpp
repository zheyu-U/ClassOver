#include "pch.h"
#include "Settings.h"






winrt::hstring Tools::getRoamingAppDataPath() {

	winrt::Windows::Storage::UserDataPaths c = winrt::Windows::Storage::UserDataPaths::GetDefault();
	return c.RoamingAppData();

}

//读文件
bool Tools::readFileIntoString(std::string Path, std::string* str)
{
	std::ifstream file{ Path, ios::in };
	/*file.open(Path, std::ios::in);*/
	
	std::string raw = 
		R"ROW_JSON(
{
    "timerCount" : 1,
    "Timer0":{
        "hh":10,
        "mm":30,
        "ss":8
    }
}
)ROW_JSON";


	if (!file.is_open()) {

		ofstream file_{ Path, ios::trunc | ios::out };
		file_ << raw;

		file.open(Path, ios::in);
		if (!file.is_open()) {
			MessageBox(NULL, L"打开文件错误，请手动添加", L"ClassOver 错误", MB_OK);
			MessageBox(NULL, L"In[%AppData%/ClassOver/settings.json].\nGet template file from github!", L"ClassOver 错误", MB_OK);
			return 0;
		}
	}
	//open

	//ref https://cplusplus.com/reference/fstream/ifstream/

	(*str).clear();
	char buff;
	while (file.get(buff)) (*str).push_back(buff);

	return 1;
}

bool Tools::writeFileFromString(std::string Path, std::string_view scr)
{
	std::string path_main = winrt::to_string(Tools::getRoamingAppDataPath()) + "\\ClassOver\\";
	std::string path = path_main + R"(\settings.json)";

	if (!std::filesystem::exists(path)) {
		std::filesystem::path p = path_main;
		std::filesystem::create_directories(p);
	}

	ofstream file{ path,ios::trunc | ios::out };

	if (file.is_open())
	{
		file << scr;
		return true;
	}

	MessageBox(NULL, L"储存文件错误，请手动添加", L"ClassOver 错误", MB_OK);
	return false;
	
}

std::string Tools::makeName(size_t num)
{
	return "Timer" + std::to_string(num);
}

