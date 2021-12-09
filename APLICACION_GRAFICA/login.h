#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <sqlite3.h>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Login *ui;
    QString _usu_log;
    QString _contra_log;
    static int callback(void* data, int argc, char* argv[], char* campos[] );
};

#endif // LOGIN_H
