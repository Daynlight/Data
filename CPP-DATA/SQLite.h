#pragma once
// system
#include <string>
#include <vector>
// libs
#include "SQLite/sqlite3.h"

namespace Data {
	class SQLite {
	public:
		SQLite(const char* server_name, const char* user_name, const char* password);
		~SQLite();
		// methods
		template <class t_ReturnType>
		t_ReturnType querry(const char* querry = "");

	private:
		const char* server_name;
		const char* user_name;
		const char* password;
	};
};

