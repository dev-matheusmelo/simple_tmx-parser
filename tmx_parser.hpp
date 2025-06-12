#pragma once
#include <fstream>
#include <string>
#include <vector>


enum tmx_encoding {
    ENCODING_CSV
};

class simple_tmx_parser {
private:
    std::string m_file_name;
    std::vector<std::string>m_tags;

public:

    tmx_parser() { ; }
    tmx_parser(std::string file_name):m_file_name(file_name) {}
    std::string get_atribute_value(std::string tag_name, std::string atribute_name_without_equal);

    std::vector<char>get_layer_data(std::string layer_id,tmx_encoding encoding);
};


std::string simple_tmx_parser::get_atribute_value(std::string tag_name, std::string atribute_name_without_equal) {
    std::ifstream arquivo(m_file_name);
    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            if (linha.find(tag_name) != std::string::npos && linha.find(atribute_name_without_equal) != std::string::npos) {
                std::string temp_string;
                int start_index = linha.find(atribute_name_without_equal) + atribute_name_without_equal.length();
                for (auto it = linha.begin() + start_index + 2; *it != '"'; it++) {
                    temp_string += *it;
                }
                arquivo.close();
                return temp_string;
            }
        }
        arquivo.close();
        return "";
    }
    else {
        arquivo.close();
        return "";
    }
}

std::vector<char>simple_tmx_parser::get_layer_data(std::string layer_id,tmx_encoding encoding) {
    std::ifstream arquivo(m_file_name);
    std::vector<char>data;
    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            if (linha.find("<layer") != std::string::npos && linha.find("id=\"" + layer_id + "\"") != std::string::npos) {
                std::getline(arquivo, linha);
                while (std::getline(arquivo, linha)) {
                    if (encoding == tmx_encoding::ENCODING_CSV) {
                        for (char copy : linha) {
                            if (copy != ',') {
                                if (copy == '<') {
                                    return data;
                                }
                                data.push_back(copy);
                            }
                        }
                    }
                }
            }
        }
        return data;
    }
}
