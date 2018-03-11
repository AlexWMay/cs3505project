/*
 * This warehouse class is used to build warehouses for the Fooditem 
 *   storage.
 *
 * Jeremy Johnson, Al May
 * CS3505 - Spring 2018
 */


#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include "food_order.h"
#include <map>
#include <set>
#include <vector>
#include "boost/date_time/gregorian/gregorian.hpp" //include all types plus i/o
#include <boost/algorithm/string.hpp>

class warehouse
{
  
 private:
  std::string name;
  long long request_quantity;
  std::map<std::string, long long> request_map;
  std::map<std::string, std::vector<food_order> > inventory;
  std::map<std::string, long long> received_items;
  std::map<std::string, long long> requested_items;
std::map<std::string, std::vector<boost::gregorian::date> > test_inventory;
boost::gregorian::date current_day;
  
 std::string dateAsMMDDYYYY( const boost::gregorian::date& date);


 public:
  
  warehouse(std::string _name);  // Constructor
  warehouse(const warehouse & other);

void receive(std::string upc, long long q, boost::gregorian::date exp_date);
  void request(std::string upc, long long q);
  std::string end_of_day(boost::gregorian::date d);
  std::string get_name();
};
#endif


