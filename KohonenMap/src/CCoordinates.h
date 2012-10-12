/*
 * CCoordinates.h
 *
 *  Created on: 10.10.2012
 *      Author: Lag
 */

#ifndef CCOORDINATES_H_
#define CCOORDINATES_H_

#include "math.h"

class CCoordinates {
	int x_cord,y_cord;
public:
	CCoordinates():x_cord(0),y_cord(0) {};
	CCoordinates(int x,int y):x_cord(x),y_cord(y){};
	virtual ~CCoordinates() {};

	int & x()
	{
		return x_cord;
	}
	int & y()
	{
		return y_cord;
	}
	const int & x() const
	{
		return x_cord;
	}
	const int & y() const
	{
		return y_cord;
	}

	friend int distance(const CCoordinates & C1,const CCoordinates & C2)
	{
		return sqrt( pow( double(C1.x()-C2.x()) , 2.0 ) + pow( double(C1.y()-C2.y()) , 2.0 ) );
	}
};

#endif /* CCOORDINATES_H_ */
