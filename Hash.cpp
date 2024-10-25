#include "Hash.h"

namespace Data {
	BaseHash::BaseHash(const char* hash_key)
		:hash_key(hash_key) {};

	std::string BaseHash::hash_function(std::string data) {
		for (size_t index = 0; index < data.size(); index++)
			data[index] = data[index] + hash_key[index % strlen(hash_key)];
		return data;
	};

	std::string BaseHash::un_hash_function(std::string data) {
		for (size_t index = 0; index < data.size(); index++)
			data[index] = data[index] - hash_key[index % strlen(hash_key)];
		return data;
	};
};