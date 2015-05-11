#ifndef TEAMINFO_H
#define TEAMINFO_H

#include <QWidget>

namespace Ui {
class TeamInfo;
}

class TeamInfo : public QWidget
{
    Q_OBJECT

public:
    explicit TeamInfo(QWidget *parent = 0);
    ~TeamInfo();

private slots:
    void on_teamS_clicked();

    void on_stadiumS_clicked();

    void on_leagueS_clicked();

    void on_seatingS_clicked();

    void on_dateS_clicked();

private:
    Ui::TeamInfo *ui;
};

#endif // TEAMINFO_H
