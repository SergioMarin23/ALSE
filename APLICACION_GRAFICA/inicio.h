#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Inicio; }
QT_END_NAMESPACE

class Inicio : public QMainWindow
{
    Q_OBJECT

public:
    Inicio(QWidget *parent = nullptr);
    ~Inicio();

private slots:
    void on_LOGIN_BUTTON_clicked();
    void on_REGIS_BUTTON_clicked();

private:
    Ui::Inicio *ui;
};
#endif // INICIO_H
