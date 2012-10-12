/*
 * CNeuron.h
 *
 *  Created on: 10.10.2012
 *      Author: Lag
 */

#ifndef CNEURON_H_
#define CNEURON_H_

#include "CSmartArray.h"
#include "CPixel.h"
#include "CCoordinates.h"

class CNeuron : public CSmartArray<CPixel> ,public CCoordinates{

public:

	CNeuron(){};
	CNeuron(const CNeuron& N):CSmartArray<CPixel>(N),CCoordinates(N)
	{

	}
	CNeuron(int NeuronSize,int x,int y):CSmartArray<CPixel>(NeuronSize,NeuronSize),CCoordinates(x,y) {}
	virtual ~CNeuron() {}

	friend double NeighbourMesure(const CNeuron & N1,const CNeuron & N2,int IterNum,int NeuronsNumber=2)
	{
		double alpha= IterNum<10 ? 1.0 : pow(double(IterNum-9),-0.2);

		return alpha*exp( -pow( distance(N1,N2) ,2.0)/(10*sqrt((double)NeuronsNumber/(double)IterNum)) );
	}
	CNeuron operator+(const CNeuron & N) const
	{
		CNeuron result(*this);
		CSmartArray<CPixel>::operator +(N);
		return result;
	}
	CNeuron operator-(const CNeuron & N) const
	{
		CNeuron result(*this);
		CSmartArray<CPixel>::operator -(N);
		return result;
	}
	template<typename R>
	CNeuron operator*(const R & Value) const
	{
		CNeuron result(*this);
		CSmartArray<CPixel>::operator *(Value);
		return result;
	}

	static const int UNUSED_COORD=-1;
};

#endif /* CNEURON_H_ */
