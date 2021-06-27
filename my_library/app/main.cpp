//#include "my_library/my_library.h"
#include <stdlib.h>
#include <QtWidgets/QApplication>
#include "CDialog.h"
#include "Wsa.h"
int main(int argc, char* argv[])
{

   // sayHello();
	QApplication a(argc, argv);
	Wsa w;
	w.setWindowTitle("样式demo");
	w.show();
	return a.exec();
}