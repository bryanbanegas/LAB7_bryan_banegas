#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "notas.h"
#include "productos.h"
#include "QList"
#include "QXmlStreamReader"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_agregarButton_clicked();

    void on_agregarAlArchivo_clicked();

    void on_leerElArchivo_clicked();

    void on_agregarAlArchivoSiPasaron_clicked();

    void on_imprimirButton_clicked();

    void on_agregarButton_2_clicked();

    void on_imprimirButton_2_clicked();

    void on_agregarAlArchivo_2_clicked();

    void on_leerElArchivo_2_clicked();

    void on_modificarButton_clicked();

    void on_leerArhivoCSV_clicked();

    void on_imprimirButton_3_clicked();

    void on_guardarArhivoCSV_2_clicked();

    void on_agregar_clicked();

private:
    Ui::MainWindow *ui;
    QVector<notas*> estudiantes;
    QVector<productos*> producto;
    QList<double> sumas;
    notas* f1;
    notas* f2;
    productos* f;
    int codigo=0;
};
#endif // MAINWINDOW_H
