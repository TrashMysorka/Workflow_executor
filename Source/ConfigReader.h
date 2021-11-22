//
// Created by v.babushkin on 22.11.2021.
//

#ifndef HASH_TABLE_CONFIGREADER_H
#define HASH_TABLE_CONFIGREADER_H
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <map>
using namespace std;

class ConfigReader{
private:
    string workers, args;
    int id{};
    list<pair<string, string>> priority;
    map<int, pair<string, string>> jobs;
    ifstream file;

    void separate_ids(const string& str);


    void separate(const string& str);


    void read_desc();


    void read_csed();
public:
    explicit ConfigReader(const string& filename);


    list<pair<string, string>> read_config();

};


#endif //HASH_TABLE_CONFIGREADER_H
