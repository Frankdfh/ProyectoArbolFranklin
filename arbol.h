#ifndef ARBOL_H
#define ARBOL_H

#include <QMainWindow>

namespace Ui {
class Arbol;
}

class Arbol : public QMainWindow
{
    Q_OBJECT

public:
    explicit Arbol(QWidget *parent = 0);
    ~Arbol();

private slots:
    void on_btnAgregarNodo_clicked();


private:
    Ui::Arbol *ui;
};

#endif // ARBOL_H
