/*
 * This class is used to store a quantity of an order and its 
 *    expiration date based on when it was received into a warehouse.
 *
 * Jeremy Johnson, Al May
 * CS3505 - Spring 2018
 */


#include "food_order.h"

long long quantity;
date exp_date;


food_order::food_order(long long q, date exp){

  quantity = q;
  exp_date = exp;
}

food_order::~food_order(){

}

/*
 * Returns the expiration date for the food_order.
 */
date food_order::get_expiration(){

  return exp_date;
}

/*
 * Returns the quantity value for the food_order.
 */
long long food_order::get_quantity(){

  return quantity;
}

/*
 * Subtracts the input number from quantity and makes the answer
 *    the new quantity.
 */
void food_order::subtract(long long num){

  quantity = (quantity - num);
}

