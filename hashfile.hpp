#include<openssl/cryptoerr_legacy.h>
#include <openssl/sha.h>
#include <fstream>
#include<string>
#include<sstream>
#include<iomanip>
std::string sha256_file(const std::string& path);