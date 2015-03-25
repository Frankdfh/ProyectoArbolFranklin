#include "arbol.h"
#include "ui_arbol.h"
#include <iostream>
Arbol::Arbol(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Arbol)
{
    ui->setupUi(this);
    ui->txtNodo_raiz->setHidden(true);
    ui->txtNodo_2->setHidden(true);
    ui->txtNodo_3->setHidden(true);
    ui->txtNodo_4->setHidden(true);
    ui->txtNodo_5->setHidden(true);
    ui->txtNodo_6->setHidden(true);
    ui->txtNodo_7->setHidden(true);
    ui->txtNodo_8->setHidden(true);
    ui->txtNodo_9->setHidden(true);
    ui->txtNodo_10->setHidden(true);
    ui->lblEtiqueta1->setHidden(true);
    ui->lblEtiqueta2->setHidden(true);
    ui->lblEtiqueta3->setHidden(true);
    ui->lblEtiqueta4->setHidden(true);
    ui->lblEtiqueta5->setHidden(true);
    ui->lblEtiqueta6->setHidden(true);
    ui->lblEtiqueta7->setHidden(true);
    ui->lblEtiqueta8->setHidden(true);
    ui->lblEtiqueta9->setHidden(true);
}
//Variables Extras
int matriz[10][10];
int rango=0;
int nodoPadre;
int x=0;
int y=0;
int cantidad=0;
//CLASE NODO
class Nodo
{
public:
    int valor;
    int posx;
    int posy;
    Nodo*nodoIzq,*nodoDer;

    Nodo(int valor)
    {
        this->valor=valor;
        this->posx=0;
        this->posy=0;
        nodoIzq=NULL;
        nodoDer=NULL;
    }
};
//CLASE ARBOL
class ArbolP
{
 public:
    Nodo*raiz;
    ArbolP()
    {
        raiz=NULL;
    }

    bool yaExiste(Nodo*nodoActual,Nodo*nuevoNodo)
    {
        if(nuevoNodo->valor!=nodoActual->valor)
        {
            if(nuevoNodo->valor<nodoActual->valor)
            {
                if(nodoActual->nodoIzq!=NULL)
                {
                    yaExiste(nodoActual->nodoIzq,nuevoNodo);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(nodoActual->nodoDer!=NULL)
                {
                    yaExiste(nodoActual->nodoDer,nuevoNodo);
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            return true;
        }
    }

    bool Existe(Nodo*nuevoNodo)
    {
        if(raiz==NULL)
        {
            return false;
        }else
        {
            if(raiz->valor==nuevoNodo->valor)
            {
                return true;
            }else
            {
                yaExiste(raiz,nuevoNodo);
            }
        }
    }
//FUNCION INSERTAR
    void FuncInsert(Nodo*nodoActual,Nodo*nuevoNodo)
    {
        rango++;
        if(nuevoNodo->valor<nodoActual->valor)
        {
            if(nodoActual->nodoIzq==NULL)
            {
                nodoPadre=nodoActual->valor;
                if(rango==1)
                {
                    nuevoNodo->posx=nodoActual->posx-300;
                    nuevoNodo->posy=nodoActual->posy+50;
                }else
                {
                    nuevoNodo->posx=nodoActual->posx-90;
                    nuevoNodo->posy=nodoActual->posy+50;
                }
                nodoActual->nodoIzq=nuevoNodo;
                matriz[cantidad][0]=nuevoNodo->valor;
                matriz[cantidad][1]=nuevoNodo->posx;
                matriz[cantidad][2]=nuevoNodo->posy;
            }
            else
            {
                FuncInsert(nodoActual->nodoIzq,nuevoNodo);
            }
        }
        else
        {
            if(nodoActual->nodoDer==NULL)
            {
                nodoPadre=nodoActual->valor;
                if(rango==1)
                {
                    nuevoNodo->posx=nodoActual->posx+300;
                    nuevoNodo->posy=nodoActual->posy+50;
                }else
                {
                    nuevoNodo->posx=nodoActual->posx+90;
                    nuevoNodo->posy=nodoActual->posy+50;
                }
                nodoActual->nodoDer=nuevoNodo;
                matriz[cantidad][0]=nuevoNodo->valor;
                matriz[cantidad][1]=nuevoNodo->posx;
                matriz[cantidad][2]=nuevoNodo->posy;
            }
            else
            {
                FuncInsert(nodoActual->nodoDer,nuevoNodo);
            }
        }
    }

    void insertar(Nodo*nuevoNodo)
    {
        if(raiz!=NULL)
        {
            FuncInsert(raiz,nuevoNodo);
        }
        else
        {
            nuevoNodo->posx=600;
            nuevoNodo->posy=10;
            //nuevoNodo->valor=txt
            raiz=nuevoNodo;
            matriz[0][0]=nuevoNodo->valor;
            matriz[0][1]=raiz->posx;
            matriz[0][2]=raiz->posy;
        }
    }


};
//Declaracion clase arbol
ArbolP arbol;

Arbol::~Arbol()
{

    delete ui;
}

void Arbol::on_btnAgregarNodo_clicked()
{
    if(ui->txtNuevoNodo->text()!="")
    {
        if(arbol.Existe(new Nodo(ui->txtNuevoNodo->text().toInt()))==false)
        {
            rango=0;
            arbol.insertar(new Nodo(ui->txtNuevoNodo->text().toInt()));
            QString texto;
            QString rangotexto;
            QString nPadretexto;
            rangotexto.append(QString("%1").arg(rango));
            nPadretexto.append(QString("%1").arg(nodoPadre));
            ui->lblRango->setText(rangotexto);
            texto.append(QString("%1").arg(matriz[cantidad][0]));
            if(cantidad==0)
            {

                ui->txtNodo_raiz->setHidden(false);
                ui->txtNodo_raiz->setText(texto);
                ui->txtNodo_raiz->setGeometry(QRect(QPoint(matriz[cantidad][1],matriz[cantidad][2]),QSize(51,20)));//matriz[cantidad][1];
                ui->txtNuevoNodo->clear();
                cantidad++;

            }else if(cantidad==1)
            {
                ui->lblEtiqueta1->setHidden(false);
                ui->lblEtiqueta1->setText("Hijo de: "+nPadretexto);
                ui->txtNodo_2->setHidden(false);
                ui->txtNodo_2->setText(texto);
                ui->txtNodo_2->setGeometry(QRect(QPoint(matriz[cantidad][1],matriz[cantidad][2]),QSize(51,20)));//matriz[cantidad][1];
                ui->lblEtiqueta1->setGeometry(QRect(QPoint(matriz[cantidad][1],(matriz[cantidad][2])-20),QSize(71,16)));
                ui->txtNuevoNodo->clear();
                cantidad++;
            }else if(cantidad==2)
            {
                ui->lblEtiqueta2->setHidden(false);
                ui->lblEtiqueta2->setText("Hijo de: "+nPadretexto);
                ui->txtNodo_3->setHidden(false);
                ui->txtNodo_3->setText(texto);
                ui->txtNodo_3->setGeometry(QRect(QPoint(matriz[cantidad][1],matriz[cantidad][2]),QSize(51,20)));//matriz[cantidad][1];
                ui->lblEtiqueta2->setGeometry(QRect(QPoint(matriz[cantidad][1],(matriz[cantidad][2])-20),QSize(71,16)));
                ui->txtNuevoNodo->clear();
                cantidad++;
            }else if(cantidad==3)
            {
                ui->lblEtiqueta3->setHidden(false);
                ui->lblEtiqueta3->setText("Hijo de: "+nPadretexto);
                ui->txtNodo_4->setHidden(false);
                ui->txtNodo_4->setText(texto);
                ui->txtNodo_4->setGeometry(QRect(QPoint(matriz[cantidad][1],matriz[cantidad][2]),QSize(51,20)));//matriz[cantidad][1];
                ui->lblEtiqueta3->setGeometry(QRect(QPoint(matriz[cantidad][1],(matriz[cantidad][2])-20),QSize(71,16)));
                ui->txtNuevoNodo->clear();
                cantidad++;
            }else if(cantidad==4)
            {
                ui->lblEtiqueta4->setHidden(false);
                ui->lblEtiqueta4->setText("Hijo de: "+nPadretexto);
                ui->txtNodo_5->setHidden(false);
                ui->txtNodo_5->setText(texto);
                ui->txtNodo_5->setGeometry(QRect(QPoint(matriz[cantidad][1],matriz[cantidad][2]),QSize(51,20)));//matriz[cantidad][1];
                ui->lblEtiqueta4->setGeometry(QRect(QPoint(matriz[cantidad][1],(matriz[cantidad][2])-20),QSize(71,16)));
                ui->txtNuevoNodo->clear();
                cantidad++;
            }else if(cantidad==5)
            {
                ui->lblEtiqueta5->setHidden(false);
                ui->lblEtiqueta5->setText("Hijo de: "+nPadretexto);
                ui->txtNodo_6->setHidden(false);
                ui->txtNodo_6->setText(texto);
                ui->txtNodo_6->setGeometry(QRect(QPoint(matriz[cantidad][1],matriz[cantidad][2]),QSize(51,20)));//matriz[cantidad][1];
                ui->lblEtiqueta5->setGeometry(QRect(QPoint(matriz[cantidad][1],(matriz[cantidad][2])-20),QSize(71,16)));
                ui->txtNuevoNodo->clear();
                cantidad++;
            }else if(cantidad==6)
            {
                ui->lblEtiqueta6->setHidden(false);
                ui->lblEtiqueta6->setText("Hijo de: "+nPadretexto);
                ui->txtNodo_7->setHidden(false);
                ui->txtNodo_7->setText(texto);
                ui->txtNodo_7->setGeometry(QRect(QPoint(matriz[cantidad][1],matriz[cantidad][2]),QSize(51,20)));//matriz[cantidad][1];
                ui->lblEtiqueta6->setGeometry(QRect(QPoint(matriz[cantidad][1],(matriz[cantidad][2])-20),QSize(71,16)));
                ui->txtNuevoNodo->clear();
                cantidad++;
            }else if(cantidad==7)
            {
                ui->lblEtiqueta7->setHidden(false);
                ui->lblEtiqueta7->setText("Hijo de: "+nPadretexto);
                ui->txtNodo_8->setHidden(false);
                ui->txtNodo_8->setText(texto);
                ui->txtNodo_8->setGeometry(QRect(QPoint(matriz[cantidad][1],matriz[cantidad][2]),QSize(51,20)));//matriz[cantidad][1];
                ui->lblEtiqueta7->setGeometry(QRect(QPoint(matriz[cantidad][1],(matriz[cantidad][2])-20),QSize(71,16)));
                ui->txtNuevoNodo->clear();
                cantidad++;
            }else if(cantidad==8)
            {
                ui->lblEtiqueta8->setHidden(false);
                ui->lblEtiqueta8->setText("Hijo de: "+nPadretexto);
                ui->txtNodo_9->setHidden(false);
                ui->txtNodo_9->setText(texto);
                ui->txtNodo_9->setGeometry(QRect(QPoint(matriz[cantidad][1],matriz[cantidad][2]),QSize(51,20)));//matriz[cantidad][1];
                ui->lblEtiqueta8->setGeometry(QRect(QPoint(matriz[cantidad][1],(matriz[cantidad][2])-20),QSize(71,16)));
                ui->txtNuevoNodo->clear();
                cantidad++;
            }else if(cantidad==9)
            {
                ui->lblEtiqueta9->setHidden(false);
                ui->lblEtiqueta9->setText("Hijo de: "+nPadretexto);
                ui->txtNodo_10->setHidden(false);
                ui->txtNodo_10->setText(texto);
                ui->txtNodo_10->setGeometry(QRect(QPoint(matriz[cantidad][1],matriz[cantidad][2]),QSize(51,20)));//matriz[cantidad][1];
                ui->lblEtiqueta9->setGeometry(QRect(QPoint(matriz[cantidad][1],(matriz[cantidad][2])-20),QSize(71,16)));
                ui->txtNuevoNodo->clear();
                cantidad++;
            }/*else if(cantidad==10)
            {
                ui->lblEstado->setText("Ya ha ingresado 10 Valores");
            }*/
            ui->lblEstado->setText("");

    }
        else
        {
            ui->lblEstado->setText("EL VALOR INGRESADO YA EXISTE");
        }
    }
    else
    {
        ui->lblEstado->setText("El campo esta vacio");
    }
}


