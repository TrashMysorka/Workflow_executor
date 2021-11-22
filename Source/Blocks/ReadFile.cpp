//
// Created by v.babushkin on 22.11.2021.
//

#include "ReadFile.h"
ReadFile::ReadFile(const string& arguments){
    string s;
    args.push_back(s);
    for (char i : arguments){
        args[0].push_back(i);
    }

}

void ReadFile::parse_args(){
    string filename = args[0];
    file.open(filename, ifstream::in);
    if(!file.is_open()){
        throw runtime_error("Readfile : cannot open file");
    }
}


void ReadFile::do_work(vector<string> txt){
    parse_args();
    string str;
    if (file.peek()==std::ifstream::traits_type::eof()) {
        throw runtime_error("Readfile : input file is empty");
    }
    while(!file.eof() && file){
        getline(file, str);
        if (!str.empty()){
            str += '\n';
            text.push_back(str);
        }
    }
    file.close();
}


vector<string> ReadFile::get_result(){

    return text;
}