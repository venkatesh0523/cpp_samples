
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <thread>
#include <functional>

using namespace std;

class ReadFile
{
public:
    explicit ReadFile(const char* filename) : filename(filename)
    {
    }

    void replaceAndSave1()
    {
        ifstream inputFile(filename);
        if (!inputFile.is_open())
        {
            throw runtime_error("Could not open file for reading");
        }

        vector<string> lines;
        string line;

        while (getline(inputFile, line))
        {
            if (line == "rahul")
            {
                line = "RAHUL";
            }
            if (line == "venkat")
            {
                line = "VENKAT";
            }
            lines.push_back(line);
        }

        inputFile.close();

        ofstream outputFile(filename);
        if (!outputFile.is_open())
        {
            throw runtime_error("Could not open file for writing");
        }

        for (const string& updatedLine : lines)
        {
            outputFile << updatedLine << '\n';
            cout << updatedLine << endl;
        }
    }
        void replaceAndSave2()
    {
        ifstream inputFile(filename);
        if (!inputFile.is_open())
        {
            throw runtime_error("Could not open file for reading");
        }

        vector<string> lines;
        string line;

        while (getline(inputFile, line))
        {
            if (line == "anirudh")
            {
                line = "ANIRUDH";
            }
            if (line == "meena")
            {
                line = "MEENA";
            }
            lines.push_back(line);
        }

        inputFile.close();

        ofstream outputFile(filename);
        if (!outputFile.is_open())
        {
            throw runtime_error("Could not open file for writing");
        }

        for (const string& updatedLine : lines)
        {
            outputFile << updatedLine << '\n';
            cout << updatedLine << endl;
        }
    }

private:
    string filename;
};

int main()
{
    
    
    try{
       ReadFile rf("src/rec/test.txt");
        
        // Create function objects correctly
        function<void()> func = bind(&ReadFile::replaceAndSave1, &rf);
        function<void()> func2 = bind(&ReadFile::replaceAndSave2, &rf);
        
        thread t1(func);
        thread t2(func2);
        
        t1.join();
        t2.join();
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
