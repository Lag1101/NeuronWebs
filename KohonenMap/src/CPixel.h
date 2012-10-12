/*
 * CPixel.h
 *
 *  Created on: 10.10.2012
 *      Author: Lag
 */

#ifndef CPIXEL_H_
#define CPIXEL_H_

//typedef int CPixel;

//#include "qrgb.h"

#define qRed(X)
#define qGreen(X)
#define qBlue(X)
typedef int QRgb;

class CPixel {
	int R,G,B,Y;
public:
	CPixel():R(0),G(0),B(0),Y(0){};
	CPixel(const CPixel & P):R(P.R),G(P.G),B(P.B),Y(P.Y){};
    CPixel(const QRgb & P):R(qRed(P)),G(qGreen(P)),B(qBlue(P)),Y(0){
        Y=0.33*R+0.54*G+0.11*B;
    };
	virtual ~CPixel(){};

    CPixel operator+(const CPixel & P)const
	{
		CPixel res;
		res.R=R+P.R;
		res.G=G+P.G;
		res.B=B+P.B;
		res.Y=Y+P.Y;
		return res;
	}
    CPixel operator-(const CPixel & P)const
	{
		CPixel res;
		res.R=R-P.R;
		res.G=G-P.G;
		res.B=B-P.B;
		res.Y=Y-P.Y;
		return res;
	}
    template<typename T>
    CPixel operator*(const T & value) const
    {
        CPixel res;
        res.R=R*value;
        res.G=G*value;
        res.B=B*value;
        res.Y=Y*value;
        return res;
    }

    operator double()
    {
        return Y;
    }

};

#endif /* CPIXEL_H_ */
