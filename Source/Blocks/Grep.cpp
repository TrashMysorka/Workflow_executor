//
// Created by v.babushkin on 22.11.2021.
//

#include "Grep.h"
Grep::Grep(const string& arguments) {
    string s;
    args.push_back(s);
    for (char i : arguments){
        args[0].push_back(i);
    }
}


void Grep::parse_args() {
    word = args[0];
}


void Grep::do_work(vector<string> txt){
    parse_args();
    string rword;
    for (const auto& it : txt){
        for (const auto& it1 : it){
            if(it1 != ' ' && it1 != '\n'){
                rword += it1;
            }
            else{
                if (rword == word){
                    text.push_back(it);
                    rword = "";
                    break;
                }
                else{
                    rword = "";
                }
            }
        }
    }
}


vector<string> Grep::get_result() {
    return text;
}