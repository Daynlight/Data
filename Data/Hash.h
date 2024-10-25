#pragma once
#include <string>

namespace Data {
	class IHash {
	public:
		virtual std::string hash_function(std::string data) = 0;
		virtual std::string un_hash_function(std::string data) = 0;
	};

	// [WARNING] No polish chars
	class BaseHash : public IHash {
	public:
		BaseHash(const char* hash_key);
		std::string hash_function(std::string data);
		std::string un_hash_function(std::string data);

	private:
		const char* hash_key = "";
	};

	// [FEATURE] Add more hash functions
};