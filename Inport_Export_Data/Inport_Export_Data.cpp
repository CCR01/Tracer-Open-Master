#include "Inport_Export_Data.h"


#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <ctime> 


// convert a vector with double to strings
std::vector<std::string> inportExportData::convertDoubleToString_vector_withComma(std::vector<real> vectorDouble)
{
	unsigned int size = vectorDouble.size();
	std::vector<std::string> outputVecString(size);
	real tempDouble;
	std::string tempString;
	
	for (unsigned int i = 0; i < size; i++)
	{
		tempDouble = vectorDouble.at(i);
		tempString = std::to_string(tempDouble);

		std::replace(tempString.begin(), tempString.end(), '.', ',');
		outputVecString.at(i) = tempString;
	}

	return outputVecString;

}

void inportExportData::saveDoubleInTXT(std::string locationTXT, std::string nameTXT, std::string nameDoubel, real valueToSave)
{
	std::string type = ".txt";
	std::string holeFile = locationTXT + nameTXT + type;

	std::ofstream file;
	file.open(holeFile, std::ios_base::app);
	if (file.is_open())
	{
		file << nameDoubel << ": " << valueToSave << std::endl;
	}
	file.close();


}



void inportExportData::saveStringInTXT(std::string locationTXT, std::string nameTXT, std::string stringToSave)
{
	std::string type = ".txt";
	std::string holeFile = locationTXT + nameTXT + type;

	std::ofstream file;
	file.open(holeFile, std::ios_base::app);

	auto end = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	//std::cout << "finished computation at " << std::ctime(&end_time)


	if (file.is_open())
	{
		file << "________________________" << std::endl;
		file << stringToSave << std::endl;
		file << std::ctime(&end_time) << std::endl;
		file << "________________________" << std::endl;
	}

	file.close();

}

void inportExportData::makeLineInTXT(std::string locationTXT, std::string nameTXT)
{
	std::string type = ".txt";
	std::string holeFile = locationTXT + nameTXT + type;

	std::ofstream file;
	file.open(holeFile, std::ios_base::app);
	if (file.is_open())
	{
		file << "________________________" << std::endl;
	}
	file.close();
}

void inportExportData::makeSpaceLineInTXT(std::string locationTXT, std::string nameTXT)
{
	std::string type = ".txt";
	std::string holeFile = locationTXT + nameTXT + type;

	std::ofstream file;
	file.open(holeFile, std::ios_base::app);
	if (file.is_open())
	{
		file << "" << std::endl;
	}
	file.close();

}

void inportExportData::exportDataToExcel(std::string locationExcel, std::string nameExcel, std::string nameDouble, real valueToSave)
{
	std::string type = ".csv";
	std::string holeFile = locationExcel + nameExcel + type;
	std::ofstream outData;
		


	outData.open(holeFile, std::ios::app);
	if (outData.is_open())
	{
		//outData << "" << std::endl;
		outData << nameDouble << ";" << valueToSave << std::endl;
		//outData << "" << std::endl;

	}
	
}

void inportExportData::exportDataToExcel_vector(std::string locationExcel, std::string nameExcel, std::string nameDouble, std::vector<real> valueToSave)
{
	std::string type = ".csv";
	std::string holeFile = locationExcel + nameExcel + type;
	std::ofstream outData;

	unsigned int numberOfValues = valueToSave.size();

	std::vector<std::string> stringToSave = convertDoubleToString_vector_withComma(valueToSave);


	outData.open(holeFile, std::ios::app);
	if (outData.is_open())
	{
		switch (numberOfValues)
			{
				case 1:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << std::endl;
					break;
				}

				case 2:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << std::endl;
					break;
				}

				case 3:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << std::endl;
					break;
				}

				case 4:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << std::endl;
					break;
				}

				case 5:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";" << stringToSave.at(4) << std::endl;
					break;
				}

				case 6:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";" << stringToSave.at(4) << ";" << stringToSave.at(5) << std::endl;
					break;
				}

				case 7:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";" << stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << std::endl;
					break;
				}

				case 8:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";" << stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) <<  std::endl;
					break;
				}

				case 9:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";" << stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) << ";" << stringToSave.at(8) << std::endl;
					break;
				}

				case 10:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";" << stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) << ";" << stringToSave.at(8) << ";" << stringToSave.at(9) << std::endl;
					break;
				}

				case 11:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";" << stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) << ";" << stringToSave.at(8) << ";" << stringToSave.at(9) << ";" << stringToSave.at(10) << std::endl;
					break;
				}


				case 12:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";" << stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) << ";" << stringToSave.at(8) << ";" << stringToSave.at(9) << ";" << stringToSave.at(10) << ";" << stringToSave.at(11) << std::endl;
					break;
				}

				case 13:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";" << stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) << ";" << stringToSave.at(8) << ";" << stringToSave.at(9) << ";" << stringToSave.at(10) << ";" << stringToSave.at(11) << ";" << stringToSave.at(12) << std::endl;
					break;
				}

				case 14:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";" 
						    << stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) << ";" << stringToSave.at(8) << ";"
						    << stringToSave.at(9) << ";" << stringToSave.at(10) << ";" << stringToSave.at(11) << ";" << stringToSave.at(12) << ";" << stringToSave.at(13) <<  std::endl;
					break;
				}

				case 15:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";"
						<< stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) << ";" << stringToSave.at(8) << ";"
						<< stringToSave.at(9) << ";" << stringToSave.at(10) << ";" << stringToSave.at(11) << ";" << stringToSave.at(12) << ";" << stringToSave.at(13) << ";" << stringToSave.at(14) << std::endl;
					break;
				}

				case 16:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";"
						<< stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) << ";" << stringToSave.at(8) << ";"
						<< stringToSave.at(9) << ";" << stringToSave.at(10) << ";" << stringToSave.at(11) << ";" << stringToSave.at(12) << ";" << stringToSave.at(13) << ";"
						<< stringToSave.at(14) << ";" << stringToSave.at(15) << std::endl;
					break;
				}

				case 17:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";"
						<< stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) << ";" << stringToSave.at(8) << ";"
						<< stringToSave.at(9) << ";" << stringToSave.at(10) << ";" << stringToSave.at(11) << ";" << stringToSave.at(12) << ";" << stringToSave.at(13) << ";"
						<< stringToSave.at(14) << ";" << stringToSave.at(15) << ";" << stringToSave.at(16) <<  std::endl;
					break;
				}

				case 18:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";"
						<< stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) << ";" << stringToSave.at(8) << ";"
						<< stringToSave.at(9) << ";" << stringToSave.at(10) << ";" << stringToSave.at(11) << ";" << stringToSave.at(12) << ";" << stringToSave.at(13) << ";"
						<< stringToSave.at(14) << ";" << stringToSave.at(15) << ";" << stringToSave.at(16) << ";" << stringToSave.at(17) << std::endl;
					break;
				}

				case 19:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";"
						<< stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) << ";" << stringToSave.at(8) << ";"
						<< stringToSave.at(9) << ";" << stringToSave.at(10) << ";" << stringToSave.at(11) << ";" << stringToSave.at(12) << ";" << stringToSave.at(13) << ";"
						<< stringToSave.at(14) << ";" << stringToSave.at(15) << ";" << stringToSave.at(16) << ";" << stringToSave.at(17) << ";" << stringToSave.at(18) << std::endl;
					break;
				}

				case 20:
				{
					outData << nameDouble << ";" << stringToSave.at(0) << ";" << stringToSave.at(1) << ";" << stringToSave.at(2) << ";" << stringToSave.at(3) << ";"
						<< stringToSave.at(4) << ";" << stringToSave.at(5) << ";" << stringToSave.at(6) << ";" << stringToSave.at(7) << ";" << stringToSave.at(8) << ";"
						<< stringToSave.at(9) << ";" << stringToSave.at(10) << ";" << stringToSave.at(11) << ";" << stringToSave.at(12) << ";" << stringToSave.at(13) << ";"
						<< stringToSave.at(14) << ";" << stringToSave.at(15) << ";" << stringToSave.at(16) << ";" << stringToSave.at(17) << ";" << stringToSave.at(18) << ";" << stringToSave.at(19) << std::endl;
					break;
				}

				default:
				{
					std::cout << "now it is not possible so save that many datas -> change the function to export to csv" << std::endl;
					break;
				}
			}

	}

	outData.close();

}

void inportExportData::exportHistogramToExcel(std::string location, std::string nameExcel, std::vector<real> histogram, unsigned int sampling, real minVal, real maxVal)
{

	int steps = (maxVal - minVal) / sampling;

	int tempMinValue = minVal;
	int tempMaxValue = minVal + steps;

	std::string minValString = std::to_string(tempMinValue);
	std::string maxValString = std::to_string(tempMaxValue);
	std::string name = minValString + " to " + maxValString;

	unsigned int sizeHisto = histogram.size();

	for (unsigned int i = 0; i < sizeHisto; ++i)
	{
		inportExportData::exportDataToExcel(location, nameExcel, name, histogram[i]);

		tempMinValue = tempMaxValue;
		tempMaxValue = tempMaxValue + steps;
		minValString = std::to_string(tempMinValue);
		maxValString = std::to_string(tempMaxValue);
		name = minValString + " to " + maxValString;
	}
}
