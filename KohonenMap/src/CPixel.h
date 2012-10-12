/*
 * CPixel.h
 *
 *  Created on: 10.10.2012
 *      Author: Lag
 */

#ifndef CPIXEL_H_
#define CPIXEL_H_

typedef int CPixel;

/*class CPixel {
	int R,G,B,Y;
public:
	CPixel():R(0),G(0),B(0),Y(0){};
	CPixel(const CPixel & P):R(P.R),G(P.G),B(P.B),Y(P.Y){};
	virtual ~CPixel(){};

	CPixel operator+(const CPixel & P)
	{
		CPixel res;
		res.R=R+P.R;
		res.G=G+P.G;
		res.B=B+P.B;
		res.Y=Y+P.Y;
		return res;
	}
	CPixel operator-(const CPixel & P)
	{
		CPixel res;
		res.R=R-P.R;
		res.G=G-P.G;
		res.B=B-P.B;
		res.Y=Y-P.Y;
		return res;
	}

	operator double()
	{
		return Y;
	}

};*/

#endif /* CPIXEL_H_ */
