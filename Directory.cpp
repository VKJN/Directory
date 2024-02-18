#include "Directory.h"

Directory::Directory(string name, string owner, string phoneNumber, string address, string occupation) {
	this->address = address;
	this->name = name;
	this->occupation = occupation;
	this->owner = owner;
	this->phoneNumber = phoneNumber;
}

vector<string> Directory::FindByName(CsvReaderWritter& csvRW, string path) {

	vector<string> coincidences;

	vector<string> dataFromFile = csvRW.readFile(csvRW.getFileName(path));
	for (auto el : dataFromFile) {
		vector<string> dataParts = csvRW.splitString(el, ';');
		for (int i = 0; i < dataParts.size(); i++) {
			if (name == dataParts[i]) {
				coincidences.push_back(dataParts[i]);
				continue;
			}
		}
	}

	return coincidences;
}

vector<string> Directory::FindByOwner(CsvReaderWritter& csvRW, string path) {
	vector<string> dataFromFile = csvRW.readFile(csvRW.getFileName(path));

	vector<string> coincidences;

	for (auto el : dataFromFile) {
		vector<string> dataParts = csvRW.splitString(el, ';');
		for (int i = 0; i < dataParts.size(); i++) {
			if (owner == dataParts[i]) {
				// Цикл для записи всех данных dataParts в coincidences
				for (int j = 0; j < dataParts.size(); j++) {
					coincidences.push_back(dataParts[j]);
				}
				continue;
			}
		}
	}

	return coincidences;
}

vector<string> Directory::FindByPhoneNumber(CsvReaderWritter& csvRW, string path) {
	vector<string> coincidences;

	vector<string> dataFromFile = csvRW.readFile(csvRW.getFileName(path));
	for (auto el : dataFromFile) {
		vector<string> dataParts = csvRW.splitString(el, ';');
		for (int i = 0; i < dataParts.size(); i++) {
			if (phoneNumber == dataParts[i]) {
				coincidences.push_back(dataParts[i]);
				continue;
			}
		}
	}

	return coincidences;
}

vector<string> Directory::FindByAddress(CsvReaderWritter& csvRW, string path) {
	vector<string> coincidences;

	vector<string> dataFromFile = csvRW.readFile(csvRW.getFileName(path));
	for (auto el : dataFromFile) {
		vector<string> dataParts = csvRW.splitString(el, ';');
		for (int i = 0; i < dataParts.size(); i++) {
			if (address == dataParts[i]) {
				coincidences.push_back(dataParts[i]);
				continue;
			}
		}
	}

	return coincidences;
}

vector<string> Directory::FindByOccupation(CsvReaderWritter& csvRW, string path) {
	vector<string> coincidences;

	vector<string> dataFromFile = csvRW.readFile(csvRW.getFileName(path));
	for (auto el : dataFromFile) {
		vector<string> dataParts = csvRW.splitString(el, ';');
		for (int i = 0; i < dataParts.size(); i++) {
			if (occupation == dataParts[i]) {
				coincidences.push_back(dataParts[i]);
				continue;
			}
		}
	}

	return coincidences;
}

void Directory::writeDataInFile(CsvReaderWritter& csvRW, string path) {
	csvRW.write(path, name, owner, phoneNumber, address, occupation);
}

void Directory::showAllDataInFile(CsvReaderWritter& csvRW, string path) {
	vector<string> dataFromFile = csvRW.readFile(csvRW.getFileName(path));

	for (auto el : dataFromFile) {
		vector<string> dataParts = csvRW.splitString(el, ';');
		for (int i = 0; i < dataParts.size(); i++) {
			cout << dataParts[i] << endl;
		}
		cout << "\n";
	}
}