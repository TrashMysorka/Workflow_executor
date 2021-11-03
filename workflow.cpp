#include "workflow.h"
#include <iostream>

ReadFile::ReadFile(vector<string> arguments){
    args = std::move(arguments);
}

void ReadFile::parse_args(){
    string filename = args[0];
    file.open(filename, ifstream::in);
}


void ReadFile::do_work(vector<string> txt){
    string str;
    if(!file){

    }
    while(!file.eof() && file){
        getline(file, str);
        if (str != ""){
            //cout << "str = " << str << endl;
            text.push_back(str);
            //cout << text[0];
        }
    }
}


vector<string> ReadFile::get_result(){
    cout << text[1];
    return text;
}


WriteFile::WriteFile(vector<string> arguments){
    args = arguments;
}


void WriteFile::parse_args(){
    string filename = args[0];
    file.open(filename, ofstream::out);
}


void WriteFile::do_work(vector<string> txt){
    if (text == vector<string>(1, "empty")){
        throw exception();
    }
    for (auto it : txt){
        cout << it;
        file << it << "\n";
    }
}


Grep::Grep(vector<string> arguments) {
args = arguments;
}


void Grep::parse_args() {
    word = args[0];
}


void Grep::do_work(vector<string> txt){
    string rword;
    for (const auto& it : txt){
        for (char it1 : it){
            if(it1 != ' '){
                rword += it;
            }
            else{
                if (rword == word){
                    text.push_back(it);
                    break;
                }
            }
        }
    }
}


