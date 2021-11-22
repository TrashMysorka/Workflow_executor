//
// Created by v.babushkin on 22.11.2021.
//

#include "Sort.h"
Sort::Sort(const string& args) {
}
void Sort::parse_args() {}


void Sort::get_words(const string& str){
    string got_word;
    string new_str = str + " ";

    for(char it : new_str){
        if(it != ' ' && it!= '\n'){
            got_word += it;
        }
        else{
            if(!got_word.empty()){
                got_word += " ";
                words.push_back(got_word);
                got_word = "";
            }

        }
    }
}


bool Sort::size_comp(const string &first, const string &second) {
    if (first.size() == second.size()){
        return first < second;
    }
    else return first.size() < second.size();
}


void Sort::do_work(vector<string> txt) {
    parse_args();
    for(const auto& it : txt){
        get_words(it);
    }
    if(words.size() == 1){
        text = txt;
        return;
    }
    words.sort(size_comp);
    for(const auto& it : words){
        text.push_back(it);
    }
}


vector<string> Sort::get_result() {
    return text;
}