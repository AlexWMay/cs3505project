/*
 * This class represents a warehouse.  It contains the warehouse inventory,
 *   and funcions to receive, evaluate requests and end of day needs.
 *
 * Jeremy Johnson, Al May
 *   CS3505 - Spring 2018
 */

// TODO: End of Day: Iterate through the requested_items map, and then
// use a for loop to go through the test_inventory map to remove (use 
// the .erase(1) function) the first item (if there are any dates 
// in that food's exp dates). Once it has done that, if there are 
// still items left, then build a string to return to the main() file
// to put out as Underfilled Orders.

#include <iostream>
#include "warehouse.h"
#include "boost/date_time/gregorian/gregorian.hpp" //include all types plus i/o

// THESE VARIABLES ARE ALL DECLARED IN THE .H FILE, SO THEY DON'T NEED TO BE
// DECLARED AGAIN. TESTED TO MAKE SURE IT STILL WORKDS.
// std::string name;
// long long request_quantity;
// std::map<std::string, long long> request_map;
// std::map<std::string, std::set<food_order> > inventory;
// std::map<std::string, std::vector<food_order> > inventory;
// std::map<std::string, long long> received_items;
// std::map<std::string, long long> requested_items;

void request(std::string upc, long long q);
void receive(std::string upc, long long q);
std::string end_of_day();
std::string get_name();


warehouse::warehouse(std::string _name)
{
  name = _name;

  //INSERT LOOP(or iteration) TO SET ALL OF THE AMOUNTS IN THE 
  //    REQUEST_MAP(using the item list) TO ZERO.
}

// Copy constructor
warehouse::warehouse (const warehouse & other)
{
  name = other.name;
  current_day = other.current_day;
}


void warehouse::receive (std::string upc, long long q, boost::gregorian::date exp_date)
{
  for(long long i = 0; i < q; i++)
    {
      /*food_order fo(exp_date, food_name);
      food_name_map[upc] = food_name;
      inventory[upc].push_back(fo);*/
      test_inventory[upc].push_back(exp_date);
    }
  
}

/*
 * Takes a requested value and adds the quantity to whatever quantity
 *     has already been requested for that day and stores it back into
 *     the request_map.
 */
void warehouse::request(std::string upc, long long q, std::string food_name)
{
  food_name_map[upc] = food_name;
  // long long temp = requested_items[upc];
  // temp += q;
  requested_items[upc] += q;
  // std::cout << "Reqested amount after adding: "  << requested_items[upc] << "\n";
}

/*
 * Performs end of day tasks as follows:
 *    - Attempts to fulfill all requests.
 *    - Removes all food_orders set to expire the next day
 *
 */
void warehouse::end_of_day(boost::gregorian::date dy, food_list & list)
{
  // Fulfill requests
  // std::cout << "Warehouse: " << get_name() << "\n";
  long long req_quantity;
  std::string underfilled;
  std::string upc;
  std::string day = warehouse::dateAsMMDDYYYY(dy);

  // For each food item requested that day...
  for(std::map<std::string, long long>::iterator it = requested_items.begin(); it != requested_items.end(); ++it)
    {
      bool empty = false;
      req_quantity = it->second;
      
      upc = it->first;
      // std::cout << "Requested Item: " << upc << " Quantity: " << req_quantity << " Current inventory: " << inventory[upc].size() << " \n";
      // Subtract one item from the warehouse for every requested item
      while(!empty && req_quantity > 0)
	{
	  
	  //if(inventory[upc].empty())
	  if(test_inventory[upc].empty())
	    {
	      std::cout << day << " " << upc << " " << food_name_map[upc] << '\n'; // "NAME HERE\n";
	      empty = true;
	      // Set the requested quantity and the quantity in the requested_items
	      //     map  to zero
	      req_quantity = 0;
	      it->second = 0;
	    }
	  else if(!empty)
	    {
	      req_quantity--;
	      // inventory[upc].erase(inventory[upc].begin());
	      test_inventory[upc].erase(test_inventory[upc].begin());
	      it->second--; // = req_quantity-1;
	    // std::cout << "erase\n";
	    }
	}
    }

  requested_items.clear();

  // Remove any expired food.
  for(std::map<std::string, std::vector<food_order > >::iterator it = inventory.begin(); it != inventory.end(); ++it)
    {
      while(!it->second.empty() && it->second.front().get_expiration() == dy)
	{
	  it->second.erase(it->second.begin());
	  // std::cout << "EXP\n";
	}
    }



  // Set request qantity to zero after requests are filled.
  date_duration dd(1);
  current_day = current_day + dd;
  // return "";
}

std::string warehouse::get_name()
{
  return name;
}


// HELPER FUNCTION TO CONVERT DATE


/*
 * Following 9 lines of code obtained from: https://stackoverflow.com/questions/7162457/how-to-convert-boostgregoriandate-to-mm-dd-yyyy-format-and-vice-versa
 */
const std::locale fmt(std::locale::classic(),
                      new boost::gregorian::date_facet("%m/%d/%Y"));
std::string warehouse::dateAsMMDDYYYY( const boost::gregorian::date& date )
{
    std::ostringstream os;
    os.imbue(fmt);
    os << date;
    return os.str();
}
