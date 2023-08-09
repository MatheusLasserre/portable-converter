#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

std::string getFileName();
bool openFile(std::ifstream &file, std::string fileName);
std::vector<std::vector<std::string>> readFile(std::ifstream &file);
std::vector<std::string> getLine(std::string const line);
std::vector<std::string> getHeader(std::string const line);
void displayLine(std::vector<std::string> const line, std::vector<std::string> const header);
// Since i don't know how many columns the csv file will have, i will create a template vector
// for each line of the csv file, and then i will create a vector of those vectors

int main()
{

    // First, for now, we will just open the file
    std::string fileName = getFileName();
    std::ifstream file;
    if (!openFile(file, fileName))
    {
        return EXIT_FAILURE;
    }

    std::vector<std::vector<std::string>> finalArray = readFile(file);

    for (const auto &line : finalArray)
    {
        displayLine(line, finalArray[0]);
    }
    // Now we will read the file line by line

    std::cout << "Hello World!" << std::endl;

    return EXIT_SUCCESS;
}

std::string getFileName()
{
    // std::string fileName;
    // std::cout << "Enter file name: ";
    // std::cin >> fileName;
    return "minor.csv";
}

bool openFile(std::ifstream &file, std::string fileName)
{
    file.open(fileName.c_str());
    if (!file.is_open())
    {
        std::cout << "Error opening file " << fileName << std::endl;
        return false;
    }
    return true;
}

std::vector<std::string> getLine(std::string const line)
{
    char separator = ',';
    std::vector<std::string> lineVector;
    int startIndex = 0, endIndex = 0;
    for (std::size_t i = 0; i <= line.size(); i++)
    {
        if (line[i] == separator || i == line.size())
        {
            endIndex = i;
            std::string temp;
            temp.append(line, startIndex, endIndex - startIndex);
            lineVector.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return lineVector;
}
std::vector<std::string> getHeader(std::string const line)
{
    char separator = ',';
    std::vector<std::string> lineVector;
    int startIndex = 0, endIndex = 0;
    for (std::size_t i = 0; i <= line.size(); i++)
    {
        if (line[i] == separator || i == line.size())
        {
            endIndex = i;
            std::string temp;

            temp.append(line, startIndex + 1, (endIndex - startIndex - 2));

            lineVector.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return lineVector;
}
std::vector<std::vector<std::string>> readFile(std::ifstream &file)
{
    std::vector<std::vector<std::string>> fileContent;
    std::string temp;
    bool firstIter = true;
    while (std::getline(file, temp))
    {
        if (firstIter)
        {
            fileContent.push_back(getHeader(temp));
            firstIter = false;
        }
        else
        {
            fileContent.push_back(getLine(temp));
        }
    }
    file.close();

    return fileContent;
};
void displayLine(std::vector<std::string> const line, std::vector<std::string> const header)
{   
    std::cout << "{";
    for (std::size_t i = 0; i < line.size(); i++)
    {
        std::cout << std::endl << header[i] << ": " << line[i] << ",";
    }
    std::cout << "\n}" << std::endl;

    std::cout << std::endl;
};