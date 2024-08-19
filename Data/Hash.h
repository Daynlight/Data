#pragma once
// system
#include <string>

namespace Data {
	class i_Hash {
	public:
		// methods
		virtual std::string hash_function(std::string data) = 0;
		virtual std::string un_hash_function(std::string data) = 0;
	};

	// [WARNING] No polish chars
	class BaseHash : public i_Hash {
	public:
		BaseHash(const char* hash_key);
		// methods
		std::string hash_function(std::string data);
		std::string un_hash_function(std::string data);

	private:
		const char* hash_key = "asd";
	};

	// [FEATURE] Add more hash functions
};