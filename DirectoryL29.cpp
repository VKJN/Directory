#include "Directory.h"
#include "CsvReaderWritter.h"

int main()
{
	Directory d1("KB", "Alex", "89612300391", "Lenin Street 2", "Alcohole");
	Directory d2("Lenta", "Bob", "88005553535", "Social Street 215", "products");
	Directory d3("5", "I", "89281234556", "Space Street 1", "products");
	Directory d4("IKEA", "Robert", "89002110381", "Orskaya Street 56", "furniture");

	CsvReaderWritter csvRW;

	d1.writeDataInFile(csvRW, "m_12.csv");
	d2.writeDataInFile(csvRW, "m_12.csv");
	d3.writeDataInFile(csvRW, "m_12.csv");
	d4.writeDataInFile(csvRW, "m_12.csv");

	d1.showAllDataInFile(csvRW, "m_12.csv");


	vector<string> result = d2.FindByOwner(csvRW, "m_12.csv");

	cout << "Number of coincidences: " << result.size() << endl << "All coincidences:" << "\n\n";

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;

	// Удаление всех данных в файле
	csvRW.clearFile("m_12.csv");
}