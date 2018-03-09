// Authors: Alex May and Jeremy Johnson.
// Project: Assigment 4. Transaction Report. CS3505.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "warehouse.h"
#include "boost/date_time/gregorian/gregorian.hpp" //include all types plus i/o
#include <boost/algorithm/string.hpp>
#include <stdlib.h>

using namespace boost::gregorian;

void end_day_for_every_warehouse();

int main()
{
    std::ifstream file( "data1.txt" );
    std::string warehouse;
    std::string warehousemark;

    std::string line;
    while (std::getline(file, line))
      {
	std::istringstream iss(line);
        
	std::string indicator;
	iss >> indicator;
	if(indicator == "FoodItem")
	  {
	    std::string UPC;
	    std::string temp_food_string;
	    std::string food_name;
	    int shelf_life = 0;
	    iss >> temp_food_string; // Pass the '-'string
	    iss >> temp_food_string; // Pass the "UPC" string
	    iss >> temp_food_string; // Pass the "Code:" string
	    iss >> UPC; // Place the UPC code
	    iss >> temp_food_string; // Pass the "Shelf" string
	    iss >> temp_food_string; // Pass the "Life:" string
	    iss >> shelf_life;
	    iss >> temp_food_string; // Pass the "Name: " string
	    std::getline(iss, food_name);
	    boost::trim(food_name);
	   
	    
	    // std::cout << shelf_life << "\n";
	    // std::cout << food_name << "\n";
	  }
	else if(indicator == "Warehouse")
	  {
	    iss >> warehousemark;
	    iss >> warehouse;
	    cs3505::warehouse test(warehouse);
	  }
	else if(indicator == "Start")
	  {
	    std::string temp_date_string;
	    iss >> temp_date_string; // Move along to pass the "Date" string on this line.
	    iss >> temp_date_string; // Move along once more to get to the MM/DD/YYY string.
	    // Initiate the m, d, y variables.
	    std::string month, day, year;
	    // Trim the current date string.
	    boost::trim_left(temp_date_string);
	    // Put the current date string into a stringstream.
	    std::stringstream tempss(temp_date_string);
	    // Parse the string between the '/'
	    std::getline(tempss, month, '/');
	    std::getline(tempss, day, '/');
	    std::getline(tempss, year, '/');
	    // Rebuild the string with YYYYMMDD
	    std::string gregdate = year;
	    gregdate += month;
	    gregdate += day;
	    // Build the date object.
	    date d(from_undelimited_string(gregdate));
 
	  }
	else if(indicator == "Receive:")
	  {
	    std::string UPC;
	    std::string str_quantity;
	    std::string str_warehouse;
	    iss >> UPC;
	    iss >> str_quantity;
	    iss >> str_warehouse;
	    char buffer[256];
	    std::strcpy(buffer, str_quantity.c_str());
	    long long quantity = std::atoll(buffer);
	    
	    // std::cout << quantity << "\n";
	  }
	else if(indicator == "Request:")
	  {
	    std::string UPC;
	    std::string str_quantity;
	    std::string str_warehouse;
	    iss >> UPC;
	    iss >> str_quantity;
	    iss >> str_warehouse;
	    char buffer[256];
	    std::strcpy(buffer, str_quantity.c_str());
	    long long quantity = std::atoll(buffer);
	    
	  }
	else if(indicator == "Next")
	  {
	    // Iterate through all of the warehouses and perform an end of day operation.
	  }
	else if(indicator == "End")
	  {
	   
	    return 0;
	  }
        
      }

    std::cout << "end of main" << std::endl;
    
    return 0;
}
