/*
 * This class is used to store a quantity of an order and its 
 *    expiration date based on when it was received into a warehouse.
 *
 * Jeremy Johnson, Al May
 * CS3505 - Spring 2018
 */


#include "food_order.h"
#include "boost/date_time/gregorian/gregorian.hpp" //include all types plus i/o

food_order::food_order(date exp, std::string _name)
{
  exp_date = exp;
  name = _name;
}

food_order::~food_order()
{

}

/*
 * Returns the expiration date for the food_order.
 */
date food_order::get_expiration()
{
  return exp_date;
}

std::string food_order::get_name()
{
  return name;
}

