#include "SQLite.h"

namespace Data {
	SQLite::SQLite(const char* server_name, const char* user_name, const char* password) {
	};

	SQLite::~SQLite() {
	};
	
	template <class t_ReturnType>
	t_ReturnType SQLite::querry(const char* querry) {
	};
};