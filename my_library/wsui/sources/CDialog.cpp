#include "CDialog.h"
#include "ui_CDialog.h"

CDialog::CDialog(QWidget * parent) 
	: QDialog(parent) 
	, ui(new Ui::CDialog)
{
	ui->setupUi(this);
}

CDialog::~CDialog() {
	
}
