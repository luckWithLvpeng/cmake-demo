#pragma once
#include <QDialog>
#include "wsui_global.h"

namespace Ui {
	class CDialog;
}
class WSUI_EXPORT CDialog : public QDialog {
	Q_OBJECT

public:
	CDialog(QWidget * parent = Q_NULLPTR);
	~CDialog();

private:
	Ui::CDialog *ui;
};
