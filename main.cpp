// Authors: Alex May and Jeremy Johnson.
// Project: Assigment 4. Transaction Report. CS3505.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    std::ifstream file( "data1.txt" );
    
//    if ( file )
//    {
//        std::stringstream buffer;
//
//        buffer << file.rdbuf();
//
//        file.close();
//
//        buffer =
//
//        // operations on the buffer...
//    }
    
    string line;
    stringstream dosString;
    ifstream inFile;
    inFile.open (filename.c_str());
    while(getline(inFile, line))
    {
        dosString<<line<<"\r\n";
    }
    return(dosString.str());
    
    std::cout << "Report by Jeremy Johnson and Alex May" << std::endl;
    
    
    return 0;
}

