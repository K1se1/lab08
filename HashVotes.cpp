#include "HashVotes.hpp"


int HashVotes::myhash(const std::string& surname)
{
    const int k = 31, mod = 100;
    long  long h = 0;
    for (const char& c : surname) 
    {
        int x = (int) (c - 'a' + 1);
        h = (h * k + x) % mod;  
    }
    return h;
}


void HashVotes::unenrolled(const std::string& surname)
{
    int hashkey = myhash(surname);
    if(hashmap[hashkey] == surname)
    {
        duplicates++;
        return;
    }
    hashmap[hashkey] = surname;
    size++;
}



void HashVotes::enrolled(const std::string& path)
{
    std::fstream surnames(path);
    std::string surname;
    getline(surnames, surname);
    while(getline(surnames, surname))
    {
        unenrolled(surname);
    }
}


HashVotes::HashVotes(): duplicates(0), size(0)
{
    hashmap.resize(100);
}

int HashVotes::get_duplicates()
{
    return duplicates;
}

int HashVotes::get_size()
{
    return size;
}



void HashVotes::print_voters()
{
    for(const auto& surname: hashmap)
    {
        if(surname!="") std::cout <<surname << "\n";
    }
}

 std::string& HashVotes::operator[](const std::string& name) 
 {
    int hashkey = myhash(name);
    return hashmap[hashkey];
    size++;
 }