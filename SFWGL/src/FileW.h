/*=======================================================


Copyright (C) 2019  Snexus Software

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.


=========================================================*/

#pragma once

// ============== MAIN LIB PACKAGING ABSTRACTION LAYER ============== \\

#include "Template.h"
#include "Debug.h"


#ifndef _STD // checks if the _STD symbol is defined
#define _STD ::std:: // defines the _STD
#define _STD_START namespace std {
#define _STD_END }
#endif // ends the _STD

using  std::cout;
using  std::endl;



typedef struct File {
    _STD vector <_STD string> Data = {};
    int FileSize = 0;
    _STD string Name = "";
} File;


// Gets the file from a file name and file path
File GetF(_STD string FileName) {
    _STD ifstream OPS(FileName.c_str(), std::ios::binary);
    if (OPS.is_open()) {
        _STD streampos begin, end; //starts the begin and end markers for the file size
        _STD string line; // stores each line of the file for reading
        _STD vector< _STD string> returningVect; // file stored in vector

        OPS.seekg(0, std::ios::beg);
        begin = OPS.tellg();     //----------* Start of file

        while (getline(OPS, line)) { // Gets each line of the file
            returningVect.push_back(line); // appends the line to the vector
        }

        OPS.seekg(0, std::ios::end); //This gets file's start and end markers
        end = OPS.tellg();       //----------* End of file

        int size = (end - begin); // this size var stores the final size

        OPS.close(); // closes the file

        return { returningVect, int(size), FileName };
    }
    else {
        displayout(D_ERROR, "Cannot open file, the file is not in location or is open in a different program!");
        return {};
    }
}


// writes a file to a file path
bool WriteF(File file) {
    _STD ofstream OPW(file.Name.c_str(), std::ios::binary);

    if (OPW.is_open()) {
        for (auto FileWalker : file.Data) {
            OPW << FileWalker;
            OPW << "\n";
        }
        OPW.close();

        return true;
    }
    else {
        return false;
    }
}

// Disp File
void DisplayFile(File file, int line = -1) {
    displayout(D_LOG, ("Name of File: " + file.Name).c_str());
    displayout(D_LOG, ("Size of File: " + _STD to_string(file.FileSize)).c_str());
    int Indexline = 0;
    if (line < 0) {
        for (auto i : file.Data) {
            Indexline++;
            displayout(D_LOG, (_STD to_string(Indexline) + ": " + i).c_str());
        }
    }
    else {
        if (line > 0) {
            if (line < file.Data.size())
                displayout(D_LOG, (_STD to_string(Indexline) + ": " + file.Data[line]).c_str());
        }
    }

    cout << endl;
}

// checks if a word is in a file or if the file name matches the keyword
bool FindIn(File Inputfile, std::string Keyword) {
    if (Inputfile.Name != "") {
        for (auto i : Inputfile.Data) {
            if (i.find(Keyword) != std::string::npos) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    else {
        displayout(D_WARNING, "Can't Find in file if file is not open ---");
    }
    return false;
}

// create a new file
File Fcreate(std::string file, std::vector<std::string> InitiingData) {
    File Tempfile; // making the file and setting each file part insures that the find with be null
    Tempfile.Data = InitiingData; // setting file data ---
    Tempfile.FileSize = InitiingData.size();
    Tempfile.Name = file;

    return Tempfile; // returns the file, if there is not any file data then this will return a null
}

// Del File
void DelF(File& file) {
#ifdef __linux   
    system(_STD string("rm -r " + file.Name).c_str());
#elif _WIN32   
    system(_STD string("del " + file.Name).c_str());
#endif
    displayout(D_WARNING, ("File: " + file.Name + " Was Deleted!").c_str());

    File f;
    file = f;
}

