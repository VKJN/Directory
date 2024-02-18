#include "CsvReaderWritter.h"

vector<string> CsvReaderWritter::readFile(string path) {
    vector<string> lines;
    ifstream file(path);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
    }
    file.close();
    return lines;
}

string CsvReaderWritter::getFileName(string path) {
    reverse(path.begin(), path.end());

    string name = "";

    for (int i = 0; i < path.size(); i++) {
        if (path[i] != '\\') {
            name += path[i];
        }
        else {
            break;
        }
    }

    reverse(name.begin(), name.end());

    return name;
}

vector<string> CsvReaderWritter::splitString(string tr, char splitter) {
    vector<string> buf;
    string line;

    for (auto i : tr) {
        if (i == splitter) {
            buf.push_back(line);
            line.clear();
        }
        else {
            line += i;
        }
    }
    buf.push_back(line);

    return buf;
}

void CsvReaderWritter::write(string path, string name, string owner, string phoneNumber, string address, string occupation) {
    ofstream out(getFileName(path), ios::app);
    if (out.is_open()) {
        out << name << ";" << owner << ";" << phoneNumber << ";" << address << ";" << occupation << "\n";
    }
    out.close();
}

void CsvReaderWritter::clearFile(string path) {
    std::fstream file(path, std::ios::out | std::ios::trunc);

    file.close();
}