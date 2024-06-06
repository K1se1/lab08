#include "hashfile.hpp"
std::string sha256_file(const std::string& path)
{
    int bufSize; 
    std::fstream file(path, std::ios_base::in | std::ios_base::binary);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    file.seekg(0, std::ios::end);
    bufSize = file.tellg(); 
    file.seekg(0, std::ios::beg);
    char *buffer = new char[bufSize];
    int bytesRead = 0;
    file.read(buffer, bufSize);
    SHA256_Update(&sha256, buffer, bufSize);
    SHA256_Final(hash, &sha256);
    file.close();
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
    return 0;
}