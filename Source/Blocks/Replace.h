//
// Created by v.babushkin on 22.11.2021.
//

#ifndef HASH_TABLE_REPLACE_H
#define HASH_TABLE_REPLACE_H
#include "IWorker.h"

class Replace : public IWorker{
private:
    string word1, word2;


    vector<string> words;


    void get_words(const string& str);


    string replace_words();


    void parse_args() override;
public:
    explicit Replace(const string& arguments);


    void do_work(vector<string> txt) override;


    vector<string> get_result() override;
};
#endif //HASH_TABLE_REPLACE_H
