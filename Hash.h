#pragma once
// system
#include <string>

namespace Data {
	/* [INFO]
	i_Hash is an interface class
	if you want to create a new hash class, 
	you need to inherit from this class */
	class i_Hash {
	public:
		// methods
		virtual std::string hash_function(std::string data) = 0;
		virtual std::string un_hash_function(std::string data) = 0;
	};

	/* [INFO]
	BaseHash is class that contain 
	basic hash function it is nothing 
	fancy only simple add hash_key char 
	values to every element of data */
	class BaseHash : public i_Hash {
	public:
		BaseHash(const char* hash_key);
		// methods
		std::string hash_function(std::string data);
		std::string un_hash_function(std::string data);

	private:
		const char* hash_key;
	};

	// [FEATURE] Add more hash functions
};