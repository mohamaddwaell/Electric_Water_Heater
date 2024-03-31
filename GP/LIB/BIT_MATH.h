/*
 * BIT_MATH.h
 *
 * Created: 29-Jan-24 1:45:20 PM
 *  Author: Lenovo
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(x,n)  x=x|(1<<n)
#define CLEAR_BIT(x,n) x=x&(~(1<<n))
#define GET_BIT(x,n) ((x>>n)&1)
#define TOGGLE(x,n) x=x^(1<<n)	



#endif /* BIT_MATH_H_ */