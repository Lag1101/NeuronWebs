//============================================================================
// Name        : KohonenMap.cpp
// Author      : Lomanov Vasiliy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CKohonenMap.h"

using namespace std;

int main() {

	try{
	CKohonenMap Web(10,11);

	int w(100),h(100);
	CPixel * img=new CPixel[w*h];
	for(int i=0;i<w*h;i++)
		img[i]=rand();

	Web.Initialize(img,w,w,h);

	Web.Teaching(img,w,w,h,1);

	cout<<"Hello"<<endl;
	delete [] img;
	}
	catch(const std::string & exc)
	{
		cout<<exc<<endl;
	}
	return 0;
}
