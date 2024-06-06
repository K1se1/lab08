#include<string>
#include<fstream>
#include<vector>
#include<iostream>
class HashVotes
{
    private:
    std::vector<std::string> hashmap;
    int duplicates;
    int size;
    int myhash(const std::string& surname);
    public:
    HashVotes();
    void enrolled(const std::string& path);
    void unenrolled(const std::string& surname);
    int get_size();
    int get_duplicates();
    void print_voters();
    std::string& operator[](const std::string& name);

};
