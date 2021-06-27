#include "Wsa.h"
#include "ui_Wsa.h"

Wsa::Wsa(QWidget * parent)
	: QDialog(parent) 
	, ui(new Ui::Wsa)
{
	ui->setupUi(this);
}

Wsa::~Wsa() {
	
}
