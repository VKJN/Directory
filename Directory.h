#pragma once
#include "Header.h"
#include "CsvReaderWritter.h"

class Directory {
private:
	string name;
	string owner;
	string phoneNumber;
	string address;
	string occupation;
public:
	Directory(string name, string owner, string phoneNumber, string address, string occupation);

	vector<string> FindByName(CsvReaderWritter& csvRW, string path);
	vector<string> FindByOwner(CsvReaderWritter& csvRW, string path);
	vector<string> FindByPhoneNumber(CsvReaderWritter& csvRW, string path);
	vector<string> FindByAddress(CsvReaderWritter& csvRW, string path);
	vector<string> FindByOccupation(CsvReaderWritter& csvRW, string path);

	void writeDataInFile(CsvReaderWritter& csvRW, string path);

	void showAllDataInFile(CsvReaderWritter& csvRW, string path);
};