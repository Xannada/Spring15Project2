#ifndef LANDINGWIN_H
#define LANDINGWIN_H

#include "MainHeader.h"
#include <QDialog>

namespace Ui {
class LandingWin;
}

class LandingWin : public QDialog
{
    Q_OBJECT

public:
    explicit LandingWin(QWidget *parent = 0);
    ~LandingWin();

private slots:

private:
    Ui::LandingWin *ui;
    ClickLabel EnterLink;
};

#endif // LANDINGWIN_H
