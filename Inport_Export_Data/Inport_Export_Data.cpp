#include "Inport_Export_Data.h"
#include "..\oftenUseNamespace\oftenUseNamespace.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <ctime> 

#include <cstdlib>
#include "opencv/cv.h"
#include "opencv/ml.h"


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

std::string inportExportData::convertDoubleToString_withComma(real value)
{
	
	std::string string;
		
	string = std::to_string(value);
	std::replace(string.begin(), string.end(), '.', ',');

	return string;
}

void inportExportData::saveDoubleInTXT(std::string locationTXT, std::string nameTXT, std::string nameDoubel, real valueToSave)
{
	std::string type = ".txt";

	int sizeLocEx = locationTXT.size() - 1;
	char lastCharLocEx = locationTXT[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = locationTXT + nameTXT + type;
	}
	else
	{
		holeFile = locationTXT + "/" + nameTXT + type;
	}


	std::ofstream file;
	file.open(holeFile, std::ios_base::app);
	if (file.is_open())
	{
		file << nameDoubel << ": " << valueToSave << std::endl;
	}
	file.close();


}

void inportExportData::exportIntVecInTXT(std::string locationTXT, std::string nameTXT, std::string nameValues, std::vector<int> value_vec, bool clearTXT)
{
	std::string type = ".txt";

	int sizeLocEx = locationTXT.size() - 1;
	char lastCharLocEx = locationTXT[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = locationTXT + nameTXT + type;
	}
	else
	{
		holeFile = locationTXT + "/" + nameTXT + type;
	}

	if (clearTXT)
	{
		clearDataInTXT(locationTXT, nameTXT);
	}


	unsigned int sizeVec = value_vec.size();
	int tempValue{};

	std::ofstream file;
	file.open(holeFile, std::ios_base::app);
	if (file.is_open())
	{
		file << nameValues << std::endl;
		for (unsigned int i = 0; i < sizeVec; ++i)
		{
			tempValue = value_vec[i];
			file << tempValue << std::endl;
		}
	}
	
	file.close();
}



void inportExportData::saveStringInTXT_includingTime(std::string locationTXT, std::string nameTXT, std::string stringToSave)
{
	std::string type = ".txt";
	
	int sizeLocEx = locationTXT.size() - 1;
	char lastCharLocEx = locationTXT[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = locationTXT + nameTXT + type;
	}
	else
	{
		holeFile = locationTXT + "/" + nameTXT + type;
	}

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

void inportExportData::saveStringInTXT(std::string locationTXT, std::string nameTXT, std::string stringToSave)
{
	std::string type = ".txt";

	int sizeLocEx = locationTXT.size() - 1;
	char lastCharLocEx = locationTXT[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = locationTXT + nameTXT + type;
	}
	else
	{
		holeFile = locationTXT + "/" + nameTXT + type;
	}

	std::ofstream file;
	file.open(holeFile, std::ios_base::app);


	if (file.is_open())
	{
		file << stringToSave << std::endl;
	}

	file.close();
}

void inportExportData::makeLineInTXT(std::string locationTXT, std::string nameTXT)
{
	std::string type = ".txt";

	int sizeLocEx = locationTXT.size() - 1;
	char lastCharLocEx = locationTXT[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = locationTXT + nameTXT + type;
	}
	else
	{
		holeFile = locationTXT + "/" + nameTXT + type;
	}

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
	
	int sizeLocEx = locationTXT.size() - 1;
	char lastCharLocEx = locationTXT[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = locationTXT + nameTXT + type;
	}
	else
	{
		holeFile = locationTXT + "/" + nameTXT + type;
	}

	std::ofstream file;
	file.open(holeFile, std::ios_base::app);
	if (file.is_open())
	{
		file << "" << std::endl;
	}
	file.close();

}


void inportExportData::clearDataInTXT(std::string locationTXT, std::string nameTXT)
{
	std::string type = ".txt";

	int sizeLocEx = locationTXT.size() - 1;
	char lastCharLocEx = locationTXT[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = locationTXT + nameTXT + type;
	}
	else
	{
		holeFile = locationTXT + "/" + nameTXT + type;
	}

	std::ofstream file;
	file.open(holeFile, std::ofstream::out | std::ofstream::trunc);

}


void inportExportData::exportDataToExcel(std::string locationExcel, std::string nameExcel, std::string nameDouble, real valueToSave)
{
	std::string type = ".csv";

	int sizeLocEx = locationExcel.size() - 1;
	char lastCharLocEx = locationExcel[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = locationExcel + nameExcel + type;
	}
	else
	{
		holeFile = locationExcel + "/" + nameExcel + type;
	}


	std::ofstream outData;
	outData.open(holeFile, std::ios::app);
	std::string stringToSave = convertDoubleToString_withComma(valueToSave);
	if (outData.is_open())
	{
		//outData << "" << std::endl;
		outData << nameDouble << ";" << stringToSave << std::endl;
		//outData << "" << std::endl;

	}
	
}

void inportExportData::removeDateCSV(std::string location, std::string name)
{
	std::string type = ".csv";

	int sizeLocEx = location.size() - 1;
	char lastCharLocEx = location[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = location + name + type;
	}
	else
	{
		holeFile = location + "/" + name + type;
	}

	// removing the existing file
	remove((holeFile).c_str());

	// renaming the new file with the existing file name
	//rename("reportcardnew.csv", "reportcard.csv");


}

void inportExportData::exportDataToExcel_vector(std::string locationExcel, std::string nameExcel, std::string nameDouble, std::vector<real> valueToSave)
{
	std::string type = ".csv";

	int sizeLocEx = locationExcel.size() - 1;
	char lastCharLocEx = locationExcel[sizeLocEx];
	std::string holeFile;
	if (lastCharLocEx == '/')
	{
		holeFile = locationExcel + nameExcel + type;
	}
	else
	{
		holeFile = locationExcel  + "/" + nameExcel + type;
	}

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

// export a cv::mat to excel
void inportExportData::exportCV_MatToExcel(cv::Mat matToExport, std::string location, std::string nameFile)
{
	unsigned int hight = matToExport.size().height;

	std::string loactionAndFile = location + "/" + nameFile + ".csv";

	// delete all date in excel file
	std::ofstream del;
	del.open(loactionAndFile, std::ofstream::out | std::ofstream::trunc);
	del.close();
	
	std::ofstream write;
	write.open(loactionAndFile, std::ios::app);

	std::string tempString;
	cv::Mat exportMat_float{};
	matToExport.convertTo(exportMat_float, CV_64F);
	for (unsigned int i = 0; i < hight; ++i)
	{
		// fill matrix date to csv
		if (write.is_open())
		{

			tempString = saveOneRowAsString(i, exportMat_float);
			tempString = oftenUse::replacePointByComma(tempString);

			write << tempString << std::endl;
		}
		
		
		
	}

	write.close();

}

std::string inportExportData::saveOneRowAsString(unsigned int rowNumber, const cv::Mat mat)
{
	unsigned int width = mat.size().width;

	real tempVal{};
	std::string tempString{};
	std::string returnString{};

	std::ostringstream oss;
	std::string numberAsString = oss.str(); // stores "4.78165e-143" 



	for (unsigned int i = 0; i < width; ++i)
	{

		tempVal = mat.at<real>(rowNumber, i);
		std::ostringstream oss;
		oss << std::setprecision(20) << tempVal;
 
		tempString = oss.str();
		returnString = returnString + tempString + ";";

	}

	return returnString;
}

// inport txt to cv::Mat
cv::Mat inportExportData::importTXTtoCVmat(std::string location, std::string name, unsigned int maxRows, unsigned int maxCol)
{
	std::string totalLocaltionAndFile = location + "/" + name + ".txt";
	std::ifstream infile(totalLocaltionAndFile);
	std::vector<std::vector<real> > numbers;
	std::string temp;

	while (std::getline(infile, temp))
	{
		std::istringstream buffer(temp);
		std::vector<real> line((std::istream_iterator<real>(buffer)),
			std::istream_iterator<real>());

		numbers.push_back(line);
	}


	// Now add all the data into a cv::Mat
	cv::Mat Mat = cv::Mat::zeros(maxRows, maxCol, CV_64F);
	// Loop over vectors and add the data
	for (int rows = 0; rows < maxRows; rows++) {
		for (int cols = 0; cols < maxCol; cols++)
		{
			Mat.at<real>(rows, cols) = numbers[rows][cols];

		}
	}


	return Mat;

}

// inport csv to cv::mat
cv::Mat inportExportData::importCSVtoCVmat(std::string location, std::string name)
{
	std::string totalLocaltionAndFile = location + "/" + name + ".csv";

	std::ifstream inputfile(totalLocaltionAndFile);
	std::string current_line;
	// vector allows you to add data without knowing the exact size beforehand
	std::vector< std::vector<real> > all_data;
	// Start reading lines as long as there are lines in the file
	while (std::getline(inputfile, current_line)) 
	{
		// Now inside each line we need to seperate the cols
		std::vector<real> values;
		std::stringstream temp(current_line);
		std::string single_value;
		while (getline(temp, single_value, ';')) 
		{
			// convert the string element to a integer value
			single_value.c_str();
			std::replace(single_value.begin(), single_value.end(), ',', '.');
			values.push_back(std::atof(single_value.c_str()));
		}
		// add the row to the complete data vector
		all_data.push_back(values);
	}

	// Now add all the data into a Mat element
	cv::Mat vect = cv::Mat::zeros((int)all_data.size(), (int)all_data[0].size(), CV_64F);
	// Loop over vectors and add the data
	for (int rows = 0; rows < (int)all_data.size(); rows++) 
	{
		for (int cols = 0; cols < (int)all_data[0].size(); cols++) {
			vect.at<real>(rows, cols) = all_data[rows][cols];
		}
	}

	return vect;
}

// save optical System as txt
void inportExportData::saveOpticalSystemAsTXT(OpticalSystemElement opticalSysEle, real wavelength, std::string location, std::string name)
{
	unsigned int size = opticalSysEle.getPosAndElement().size();
	opticalSysEle.setRefractiveIndexAccordingToWavelength(wavelength);
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr;
	std::shared_ptr<SurfaceIntersectionRay_LLT> tempSurface_ptr_next;

	std::string tempTypeMode_Radius;
	std::string tempTypeMode_Thickness;

	std::string tempSurfaceType{};
	real tempRadius{};
	real tempPoint_Z{};
	real tempPoint_Z_next{};
	real tempDirection_Z{};
	real semiHeight{};
	real tempPointZ = 0;
	std::string nameGlasRightSide{};
	real thickness = 0;
	real tempRefIndexRightSide{};

	clearDataInTXT(location, name);

	for (unsigned int i = 0; i < size; i++)
	{
		tempSurface_ptr = opticalSysEle.getPosAndIntersection_LLT()[i].getSurfaceInterRay_ptr();

		// surface type
		tempSurfaceType = tempSurface_ptr->getSurfaceType();

		// get radius
		tempRadius = tempSurface_ptr->getRadius();
		tempTypeMode_Radius = oftenUse::convertTypeModeToString(opticalSysEle.getPosAndElement()[i].getElementInOptSys_ptr()->getRadiusTypeModifier());
		tempDirection_Z = tempSurface_ptr->getDirection().getZ();
		// glass by name
		if (tempDirection_Z > 0)
		{
			nameGlasRightSide = opticalSysEle.getPosAndElement()[i].getElementInOptSys_ptr()->getGlassB().getNameGlas();
			tempRefIndexRightSide = tempSurface_ptr->getRefractiveIndex_B();
		}

		else if (tempDirection_Z < 0)
		{
			tempRadius = -1 * tempRadius;
			nameGlasRightSide = opticalSysEle.getPosAndElement()[i].getElementInOptSys_ptr()->getGlassA().getNameGlas();
			tempRefIndexRightSide = tempSurface_ptr->getRefractiveIndex_A();
		}


		// get tempPoint
		tempTypeMode_Thickness = oftenUse::convertTypeModeToString(opticalSysEle.getPosAndElement()[i].getElementInOptSys_ptr()->getPointTypeModifier_Z());
		if (i < size - 1)
		{
			tempSurface_ptr_next = opticalSysEle.getPosAndIntersection_LLT()[i + 1].getSurfaceInterRay_ptr();
			tempPoint_Z = tempSurface_ptr->getPoint().getZ();
			tempPoint_Z_next = tempSurface_ptr_next->getPoint().getZ();
		}

		else
		{
			tempPoint_Z = 99.0;
			tempPoint_Z_next = 99.0;
		}

		thickness = tempPoint_Z_next - tempPoint_Z;

		// get semiHeight
		semiHeight = tempSurface_ptr->getSemiHeight();

		// convert values to string
		int precision = 5;
		std::string tempSurfaceNumString = std::to_string(i);

		std::string tempRadiusString;
		if (tempRadius > 999.0)
		{
			tempRadiusString  = "INF     ";
		}

		else if (tempRadius < -999.0)
		{
			tempRadiusString = "-INF     ";
		}
		else
		{
			tempRadiusString = to_string_with_precision_double(tempRadius, precision);
		}
				
		std::string tempThicknessString = to_string_with_precision_double(thickness, precision);
		std::string tempRefIndexRightSideSting = to_string_with_precision_double(tempRefIndexRightSide, precision);
		std::string tempSemiHeightString = to_string_with_precision_double(semiHeight, precision);

		std::string totalStringToSave = "surface: " + tempSurfaceNumString + '\t' + tempSurfaceType + '\t' + "radius: " + tempRadiusString + " " + tempTypeMode_Radius +
			'\t' + "thickness: " + tempThicknessString + " " + tempTypeMode_Thickness + '\t' + "glass: " + nameGlasRightSide +
			'\t' + "refIndex: " + tempRefIndexRightSideSting + '\t' + "semi height: " + '\t' + tempSemiHeightString;
	
		saveStringInTXT(location, name, totalStringToSave);
	
	}


}

// convert to string with precision
// https://stackoverflow.com/questions/16605967/set-precision-of-stdto-string-when-converting-floating-point-values
std::string inportExportData::to_string_with_precision_double(real a_value, const int n)
{
	std::ostringstream out;
	out.precision(n);
	out << std::fixed << a_value;
	return out.str();
}