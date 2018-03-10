/*
 * This food_order class is used to store a quantity of an order and 
 *    its expiration date based on when it was received.
 *
 * Jeremy Johnson, Al May
 * CS3505 - Spring 2018
 */


#ifndef FOOD_ORDER_H
#define FOOD_ORDER_H

#include "boost/date_time/gregorian/gregorian.hpp"

using namespace boost::gregorian;


class food_order
{

 private:
  long long quantity;
  date exp_date;

 public:

  food_order(long long q, date exp);  // Constructor

  ~food_order();  // Destructor

  date get_expiration();
  long long get_quantity();
  void subtract(long long num);
};


#endif
