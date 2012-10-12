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

	CKohonenMap Web(20,11);

<<<<<<< HEAD
=======
	int w(100),h(100);
	CPixel * img=new CPixel[w*h];

	Web.Initialize(img,w,w,h);

	Web.Teaching(img,w,w,h,1);

	delete [] img;

>>>>>>> added function for teaching web
	return 0;
}
