#pragma once
#include <vector>
#include <string>

// [ToDo] Finish SQLServer Library or seperate to mysql
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>

namespace Data {
	class SQLServer {
	public:
		SQLServer(const char* server_name, const char* user_name, const char* password);
		~SQLServer();
		template <class T> 
		T querry(const char* querry = "");

	private:
		const char* server_name;
		const char* user_name;
		const char* password;
	};
};

