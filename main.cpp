// Authors: Alex May and Jeremy Johnson.
// Project: Assigment 4. Transaction Report. Spring 2018 CS_3505.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "warehouse.h"
#include "food_order.h"
#include "boost/date_time/gregorian/gregorian.hpp" //include all types plus i/o
#include <boost/algorithm/string.hpp>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include "underfilled.h"
#include "food_list.h"

using namespace boost::gregorian;

std::string dateAsMMDDYYYY(const boost::gregorian::date& date);

int main()
{
    std::ifstream file( "data1.txt" );
    // std::string str_warehouse;
    std::string warehousemark;
    std::map<std::string, int> shelf_life_map;
    std::map<std::string, std::string> food_name_map;
    std::map<std::string, long long> popular_products;
    std::set<std::string> UPC_set;
    std::vector<std::string> warehouse_list;
    std::map<std::string, warehouse> warehouse_map; 
    date d;
    int days_passed = 0;
    food_list list;
    underfilled report;

    std::cout << "Report by Jeremy Johnson and Alex May\n";
    std::cout << "Underfilled Orders:\n";

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
	   
	    list.add(UPC, food_name);

	    UPC_set.insert(UPC);
	    shelf_life_map[UPC] = shelf_life;
	    food_name_map[UPC] = food_name;
	  }
	else if(indicator == "Warehouse")
	  {
	    std::string str_warehouse;
	    iss >> warehousemark; // Ignore the "-" character
	    std::getline(iss, str_warehouse);
	    boost::trim(str_warehouse);
	    // iss >> str_warehouse;
	    warehouse wh (str_warehouse);
	    warehouse_list.push_back(str_warehouse);
	    warehouse_map.insert(std::pair<std::string, warehouse>(str_warehouse, wh));
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
	    date temp_date(from_undelimited_string(gregdate));
	    d = temp_date;
	  }
	else if(indicator == "Receive:")
	  {
	    std::string UPC;
	    std::string str_quantity;
	    std::string str_warehouse;
	    std::string food_name;
	    iss >> UPC;
	    iss >> str_quantity;
	    iss >> str_warehouse;
	    char buffer[256];
	    std::strcpy(buffer, str_quantity.c_str());
	    long long quantity = std::atoll(buffer);
	    int temp_shelf_life = shelf_life_map[UPC];
	    date_duration dd(temp_shelf_life);
	    date exp_date = d + dd;
	    // food_name = food_name_map[UPC];
	    

	    std::map<std::string, warehouse>::iterator it = warehouse_map.find(str_warehouse);
	    if(it != warehouse_map.end())
	      it->second.receive(UPC, quantity, exp_date);

	    // warehouse_map[str_warehouse].receive(UPC, quantity);
	    // warehouse_map.find(str_warehouse).request(UPC, quantity);
	  }
	else if(indicator == "Request:")
	  {
	    std::string UPC;
	    std::string str_quantity;
	    std::string str_warehouse;
	    std::string food_name;
	    iss >> UPC;
	    iss >> str_quantity;
	    iss >> str_warehouse;
	    char buffer[256];
	    std::strcpy(buffer, str_quantity.c_str());
	    long long quantity = std::atoll(buffer);
	    popular_products[UPC] += quantity;
	    food_name = food_name_map[UPC];
	    // std::cout << "Food: " << food_name << " Req Amount: " << quantity << "\n";
	    std::map<std::string, warehouse>::iterator it = warehouse_map.find(str_warehouse);
	    if(it != warehouse_map.end())
	      it->second.request(UPC, quantity, food_name);

	    // warehouse_map[str_warehouse].request(UPC, quantity);
	    // warehouse_map.find(str.request(UPC, quantity);	    

	  }
	else if(indicator == "Next")
	  {
	    // Iterate through all of the warehouses and perform an end of day operation.
	    std::cout << "Day: " << d << "\n";
	    for (std::map<std::string, warehouse>::iterator it = warehouse_map.begin(); it != warehouse_map.end(); ++it)
	      {
		// std::cout << "warehouse: " << it->first << '\n';
		it->second.end_of_day(d, list);
	      }

	    std::string day = dateAsMMDDYYYY(d);
	    report.print_underfilled(day, list);
	    
	    date_duration dd(1);
	    d = d + dd;
	  }
	else if(indicator == "End")
	  {
	    // std::cout << "Day: " << d << "\n";
	    for (std::map<std::string, warehouse>::iterator it = warehouse_map.begin(); it != warehouse_map.end(); ++it)
	      {
		// std::cout << "warehouse: " << it->first << '\n';
		it->second.end_of_day(d, list);
	      }
	      
	    
	    date_duration dd(1);
	    d = d + dd;
	    // return 0;
	  }
        
      }

    //for (std::map<std::string, warehouse>::iterator it = warehouse_map.begin(); it != warehouse_map.end(); ++it)
    //std::cout << it->first << " => " << it->second.get_name() << '\n';
    
    

    std::string UPC1 = "0";
    std::string UPC2 = "0";
    std::string UPC3 = "0";
    long long hi = 0;
    long long sec_hi = 0;
    long long third_hi = 0;

    for (std::map<std::string, long long>::iterator it = popular_products.begin(); it != popular_products.end(); ++it)
      {

	if(it->second > hi || (it->second == hi && it->first < UPC1))
	  {
	    UPC3 = UPC2;
	    UPC2 = UPC1;
	    UPC1 = it->first;
	    third_hi = sec_hi;
	    sec_hi = hi;
	    hi = it->second;
	  }
	else if(it->second > sec_hi || (it->second == sec_hi && it->first < UPC2))
	  {
	    UPC3 = UPC2;
	    UPC2 = it->first;
	    third_hi = sec_hi;
	    sec_hi = it->second;
	  }
	else if(it->second > third_hi || (it->second == third_hi && it->first < UPC3))
	  {
	    UPC3 = it->first;
	    third_hi = it->second;
	  }

      }
    
    std::cout << "Most Popular Products:\n";

    if(popular_products.size() > 2)
      {
	std::cout << hi << " " << UPC1 << " " << food_name_map[UPC1] << "\n"
		  << sec_hi << " " << UPC2 << " " << food_name_map[UPC2] << "\n"
		  << third_hi << " " << UPC2 << " " << food_name_map[UPC3] << "\n";
      }
    if(popular_products.size() == 2)
      {
	std::cout << hi << " " << UPC1 << " " << food_name_map[UPC1] << "\n"
		  << sec_hi << " " << UPC2 << " " << food_name_map[UPC2] << "\n";
      }
    if(popular_products.size() == 1)
      {
	std::cout << hi << " " << UPC1 << " " << food_name_map[UPC1] << "\n";
      }
    
    
    return 0;
}


/*
 * Following 9 lines of code obtained from: https://stackoverflow.com/questions/7162457/how-to-convert-boostgregoriandate-to-mm-dd-yyyy-format-and-vice-versa
 */
const std::locale fmt(std::locale::classic(),
                      new boost::gregorian::date_facet("%m/%d/%Y"));
std::string dateAsMMDDYYYY( const boost::gregorian::date& date )
{
    std::ostringstream os;
    os.imbue(fmt);
    os << date;
    return os.str();
}

