#ifndef LANDINGWIN_H
#define LANDINGWIN_H

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
    void on_Enter_clicked();

private:
    Ui::LandingWin *ui;
};

#endif // LANDINGWIN_H
