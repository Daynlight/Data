#include "Hash.h"

namespace Data {
	BaseHash::BaseHash(const char* hash_key)
		:hash_key(hash_key) {};

	std::string BaseHash::hash_function(std::string data) {
		std::string ret = "";
		for (int index = 0; index < data.size(); index++) {
			int temp = (int)((int)data[index] + (int)hash_key[index % (sizeof(hash_key)/8)] + 100);
			ret += std::to_string(temp);
		};
		return ret;
	};

	std::string BaseHash::un_hash_function(std::string data) {
		std::string ret = "";
		int hash_count = 0;
		for (int index = 0; index < data.size(); index += 3) {
			std::string hash_string = "";
			hash_string += data[index];
			hash_string += data[index + 1];
			hash_string += data[index + 2];
			int hash_number = std::stoi(hash_string);
			ret += (char)(hash_number - (int)hash_key[hash_count % (sizeof(hash_key) / 8)] - 100);
			hash_count++;
		};
		return ret;
	};
};