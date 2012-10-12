/*
 * CSmartArray.h
 *
 *  Created on: 10.10.2012
 *      Author: Lag
 */

#ifndef CSMARTARRAY_H_
#define CSMARTARRAY_H_

#include "string.h"
#include "math.h"
#include <string>
#include <limits>
#include <iostream>

template<class T>
class CSmartArray {
	T * Array;
	int width,height;

public:
	typedef T * iterator;
	typedef const T * const const_iterator;


	CSmartArray():width(0),height(0),Array(0){}
	CSmartArray(int i_width,int i_height):width(0),height(0),Array(0){
		resize(i_width,i_height);
	}
	CSmartArray(const CSmartArray<T> & S):width(0),height(0),Array(0)
	{
		*this=S;
	}
	virtual ~CSmartArray(){
		delete [] Array;
	}


	virtual void operator=(const CSmartArray<T> & S)
	{
		if(S.Array)
		{
			this->resize(S.width,S.height);
			if(std::numeric_limits<T>::is_exact)
				memcpy(this->Array,S.Array,width*height*sizeof(T));
			else
				for(int x=0;x<Size();x++)
					Array[x]=T();
		}
		else
			throw std::string("Array was initialize");
	}
	void resize(int i_width,int i_height)
	{
		if(width!=i_width || height!=i_height || Array==0)
		{
			width=i_width;
			height=i_height;
			delete [] Array;
			Array=new T[width*height];
		}
	}


	int Width() const
	{
		return width;
	}
	int Height() const
	{
		return height;
	}
	int Size() const
	{
		return height*width;
	}

	T & at(int y,int x)
	{
		if(y<0 || x<0 || y>=height || x>=width )
			throw std::string("wrong index");

		return Array[y*width+x];
	}
	const T & at(int y,int x) const
	{
		if(y<0 || x<0 || y>=height || x>=width )
			throw std::string("wrong index");

		return Array[y*width+x];
	}
	T & operator[](int x)
	{
		return at(x/width,x%width);
	}
	const T & operator[](int x) const
	{
		return at(x/width,x%width);
	}

	virtual CSmartArray<T> operator+(const CSmartArray<T> & S) const
	{
		CSmartArray<T> res(*this);

		for(iterator it=res.begin() , itS=S.begin() ;it<res.end();++it,++itS)
		{
			*it=*it+*itS;
		}
		return res;
	}
	virtual CSmartArray<T> operator-(const CSmartArray<T> & S)const
	{
		CSmartArray<T> res(*this);

		for(iterator it=res.begin() , itS=S.begin() ;it<res.end();++it,++itS)
		{
			*it=*it-*itS;
		}
		return res;
	}
	template<class R>
	CSmartArray operator*(R Value) const
	{
		CSmartArray res(*this);

		for(iterator it=res.begin();it<res.end();++it)
		{
			*it=*it*Value;
		}
		return res;
	}
	template<class R>
	friend CSmartArray operator*(R Value,const CSmartArray & S)
	{
		return S*Value;
	}

	iterator begin() const
	{
		return Array;
	}
	iterator end() const
	{
		return &Array[width*height];
	}

	friend double SKO(const CSmartArray<T> & N1,const CSmartArray<T> & N2)
	{
		double res=0;

		for(int i=0;i<N1.Size();i++)
		{
			res+=pow( N1[i]-N2[i] , 2.0 );
		}

		return sqrt(res);
	}
};

#endif /* CSMARTARRAY_H_ */
