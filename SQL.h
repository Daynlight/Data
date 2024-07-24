#pragma once
#include "SQLite/sqlite3.h"

#include <vector>
#include <string>

namespace Data {
	class SQL {
	public:
		SQL(const char* server_name, const char* user_name, const char* password);
		~SQL();
		template <class T> 
		T querry(const char* querry = "");

	private:
		const char* server_name;
		const char* user_name;
		const char* password;
	};
};

