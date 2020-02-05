#pragma once
#include "..\LowLevelTracing/ImportantStructures.h"
#include <string>
#include <vector>

namespace inportExportData
{
	// convert a vector with double to strings
	std::vector<std::string> convertDoubleToString_vector_withComma(std::vector<real> vectorDouble);

	// export data to TXT
	void saveDoubleInTXT(std::string locationTXT, std::string nameTXT, std::string nameDoubel, real valueToSave);
	void makeLineInTXT(std::string locationTXT, std::string nameTXT);
	void makeSpaceLineInTXT(std::string locationTXT, std::string nameTXT);

	// export data to excel
	void exportDataToExcel(std::string locationExcel, std::string nameExcel, std::string nameDouble, real valueToSave);
	void exportDataToExcel_vector(std::string locationExcel, std::string nameExcel, std::string nameDouble, std::vector<real> valueToSave);
	
}