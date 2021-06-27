#pragma once
#include <QDialog>
#include "wsui_global.h"

namespace Ui {
	class Wsa;
}
class WSA_EXPORT Wsa : public QDialog {
	Q_OBJECT

public:
	Wsa(QWidget * parent = Q_NULLPTR);
	~Wsa();

private:
	Ui::Wsa*ui;
};
