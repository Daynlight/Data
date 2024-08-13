#include "Hash.h"

namespace Data {
	BaseHash::BaseHash(const char* hash_key)
		:hash_key(hash_key) {};

	std::string BaseHash::hash_function(std::string data) {
		return data;
	};

	std::string BaseHash::un_hash_function(std::string data) {
		return data;
	};
};