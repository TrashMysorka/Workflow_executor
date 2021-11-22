//
// Created by v.babushkin on 22.11.2021.
//

#include "Count.h"
Count::Count(const string& arguments) {
    args.push_back(arguments);
    amount = 0;
}


void Count::parse_args() {
    word = args[0];
}


void Count::get_words(const string &str) {
    string got_word;

    for(char it : str){
        if(it != ' ' && it!= '\n'){
            got_word += it;
        }
        else{
            words.push_back(got_word);
            got_word = "";
        }
    }
}


void Count::do_work(vector<string> txt) {
    parse_args();
    for (const auto& it : txt){
        get_words(it);
    }
    for (const auto& it : words){
        if (it == word){
            amount++;
        }
    }
}


vector<string> Count::get_result() {
    string s = to_string(amount);
    text.push_back(s);
    return text;
}