#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void word_search(string search, string file_path)
{
    string line;
    ifstream Myfile;
    Myfile.open(file_path);

    if (Myfile.is_open())
    {
        while (getline(Myfile, line))
        {
            if ((line.find(search)) != string::npos)
            {
                cout << "The word has been found: " << file_path << endl;
            }
        }
        Myfile.close();
    }
    else
    {
        cout << "Unable to access file" << endl;
    }
}

void directory_search(string search, string directory_path)
{
    // List directories and files in directory TestData:
    fs::path p;
    for (fs::directory_iterator itr(directory_path); itr != fs::directory_iterator(); ++itr)
    {
        if (fs::is_directory(itr->path()))
        {
            directory_search(search, itr->path());
        }
        if (itr->path().filename() != "." && itr->path().filename() != "..")
        {
            word_search(search, itr->path());
        }
    }
}

int main()
{
    string directory_path = "../TestData";
    string search;

    cout << "Enter the search word please" << endl;
    cin >> search;

    directory_search(search, directory_path);

    return 0;
}
