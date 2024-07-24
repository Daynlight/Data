#include "Hash.h"

namespace Data {
	BaseHash::BaseHash(const char* hash_key)
		:hash_key(hash_key) {};

	std::string BaseHash::hash_function(std::string data) {
		for (size_t count = 0; count < data.size(); count++) {
			data[count] = data[count] + hash_key[count % strlen(hash_key)];
		};
		return data;
	};

	std::string BaseHash::un_hash_function(std::string data) {
		for (size_t count = 0; count < data.size(); count++) {
			data[count] = data[count] - hash_key[count % strlen(hash_key)];
		};
		return data;
	};
};