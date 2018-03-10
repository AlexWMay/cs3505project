/*
 * This class represents a warehouse.  It contains the warehouse inventory,
 *   and funcions to receive, evaluate requests and end of day needs.
 *
 * Jeremy Johnson, Al May
 *   CS3505 - Spring 2018
 */

#include <iostream>
#include "warehouse.h"
#include "boost/date_time/gregorian/gregorian.hpp" //include all types plus i/o


std::string name;
long long request_quantity;
std::map<std::string, long long> request_map;
// std::map<std::string, std::set<food_order> > inventory;
std::map<std::string, std::vector<food_order> > inventory;
std::map<std::string, long long> received_items;
std::map<std::string, long long> requested_items;

warehouse::warehouse(std::string _name)
{
  name = _name;

  //INSERT LOOP(or iteration) TO SET ALL OF THE AMOUNTS IN THE 
  //    REQUEST_MAP(using the item list) TO ZERO.
}

void warehouse::receive (std::string upc, long long q)
{
  received_items[upc] += q;
}

/*
 * Takes a requested value and adds the quantity to whatever quantity
 *     has already been requested for that day and stores it back into
 *     the request_map.
 */
void warehouse::request(std::string upc, long long q)
{
  requested_items[upc] += q;
}

/*
 * Performs end of day tasks as follows:
 *    - Attempts to fulfill all requests.
 *    - Removes all food_orders set to expire the next day
 *
 */
void warehouse::end_of_day()
{
  
  
  
  // Set request qantity to zero after requests are filled.
  
}
