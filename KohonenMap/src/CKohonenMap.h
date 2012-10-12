/*
 * CKohonenMap.h
 *
 *  Created on: 10.10.2012
 *      Author: Lag
 */

#ifndef CKOHONENMAP_H_
#define CKOHONENMAP_H_

#include "CNeuron.h"
#include "CSmartArray.h"
#include "stdlib.h"

class CKohonenMap {
	typedef CSmartArray<CNeuron> web_t;
public:
	CKohonenMap(int WebSize,int neuron_size) : m_NeuronWeb(web_t(WebSize,WebSize)),m_NeuronSize(neuron_size)
	{
		for(int x=0;x<m_NeuronWeb.Width();x++)
			for(int y=0;y<m_NeuronWeb.Height();y++)
				m_NeuronWeb.at(y,x)=CNeuron(m_NeuronSize,x,y);
	}
	virtual ~CKohonenMap() {
		// TODO Auto-generated destructor stub
	}

	void Initialize(const CPixel * const img,int length,int width,int height)
	{
		int HalfSize=m_NeuronSize/2;

		for(int i=0;i<m_NeuronWeb.Width();i++)
			for(int j=0;j<m_NeuronWeb.Height();j++)
			{
				int x=i*(width-m_NeuronSize)/m_NeuronWeb.Width()+HalfSize;
				int y=j*(height-m_NeuronSize)/m_NeuronWeb.Height()+HalfSize;

				FillNeuronFromPointOfImage(m_NeuronWeb.at(j,i),img,length,x,y);
			}
	}

<<<<<<< HEAD
	void Teaching(const CPixel * const img,int length,int width,int height)
=======
	void Teaching(const CPixel * const img,int length,int width,int height,int iter_num)
>>>>>>> added function for teaching web
	{
		int HalfSize=m_NeuronSize/2;

		int x=rand()%(width-m_NeuronSize)+HalfSize;
		int y=rand()%(height-m_NeuronSize)+HalfSize;

		CNeuron Neuron(m_NeuronSize,CNeuron::UNUSED_COORD,CNeuron::UNUSED_COORD);

		FillNeuronFromPointOfImage(Neuron,img,length,x,y);

		web_t::iterator MostCloseNeuron = FindMostCloseNeouronToThisOne(&Neuron);

<<<<<<< HEAD

		//FillNeuronFromPointOfImage()
=======
		MoveNeuronsToThisOne(MostCloseNeuron,iter_num);
>>>>>>> added function for teaching web

	}

private:

	web_t::iterator FindMostCloseNeouronToThisOne(web_t::const_iterator Neuron)
	{
		double	min_sko=std::numeric_limits<double>::max(),
				temp_sko;

		web_t::iterator result=NULL;
		web_t::iterator it=m_NeuronWeb.begin();

		for(web_t::iterator it=m_NeuronWeb.begin();it<m_NeuronWeb.end();++it)
		{
			if(it!=Neuron)
			{
				temp_sko=SKO(*Neuron,*it);
				if(temp_sko<min_sko)
				{
					min_sko=temp_sko;
					result=it;
				}
			}
		}
		return result;
	}

	void FillNeuronFromPointOfImage(CNeuron& Neuron,const CPixel * const img,int length,int x,int y)
	{
		int HalfSize=m_NeuronSize/2;
		for(int i=-HalfSize;i<HalfSize;i++)
			for(int j=-HalfSize;j<HalfSize;j++)
			{
				Neuron.at(i+HalfSize,j+HalfSize)=img[(y+i)*length+x+j];
			}
	}

	void MoveNeuronsToThisOne(web_t::const_iterator Neuron,int iternum)
	{
		for(web_t::iterator it=m_NeuronWeb.begin();it<m_NeuronWeb.end();++it)
		{
			if(it!=Neuron)
			{
				double temp=NeighbourMesure(*it,*Neuron,iternum,m_NeuronWeb.Size());
<<<<<<< HEAD
				//CSmartArray<int> NeuronTemp=*Neuron-*it;
				//*it=*it+NeuronTemp;
=======

				CNeuron NeuronTemp( ( (*Neuron)-(*it) )*temp );

				*it=*it+NeuronTemp;
>>>>>>> added function for teaching web
			}
		}
	}

private:
	web_t m_NeuronWeb;
	int m_NeuronSize;
};

#endif /* CKOHONENMAP_H_ */
