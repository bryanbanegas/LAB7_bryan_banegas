#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_agregarButton_clicked()
{
    QString nombre=ui->lineEdit->text();
    QString notaPrueba=ui->lineEdit_2->text();
    bool ok;
    double nota=notaPrueba.toDouble(&ok);
    notas* nuevoEstudiante=new notas(nombre,nota);
    estudiantes.append(nuevoEstudiante);
}


void MainWindow::on_agregarAlArchivo_clicked()
{
    QString file="estudiantes.txt";
    f1->guardarEnArchivo(estudiantes,file);
}


void MainWindow::on_leerElArchivo_clicked()
{
    QString file="estudiantes.txt";
    estudiantes=f1->leerArchivo(file);
}


void MainWindow::on_agregarAlArchivoSiPasaron_clicked()
{
    QString file="estudiantesSiPasaron.txt";
    f2->guardarEnArchivoSiPaso(estudiantes,file);
}


void MainWindow::on_imprimirButton_clicked()
{
    QString info="";
    for(int i=0;i<estudiantes.size();i++){
        info+="Estudiante: "+estudiantes.at(i)->getNombre()+" Nota: "+QString::number(estudiantes.at(i)->getNota())+"\n";
    }
    ui->textEdit->setText(info);
}

void MainWindow::on_agregarButton_2_clicked()
{
    codigo++;
    QString nombre=ui->lineEdit_3->text();
    QString precioPrueba=ui->lineEdit_4->text();
    bool ok;
    double precio=precioPrueba.toDouble(&ok);
    int cantidad=ui->lineEdit_5->text().toInt();

    productos* nuevoProducto=new productos(codigo,nombre,precio,cantidad);
    producto.append(nuevoProducto);
}


void MainWindow::on_imprimirButton_2_clicked()
{
    QString info="";
    for(int i=0;i<producto.size();i++){
        info+=producto.at(i)->getInfo();
    }
    ui->textEdit_2->setText(info);
}


void MainWindow::on_agregarAlArchivo_2_clicked()
{
    QString file="productos.dat";
    f->guardarEnArchivo(producto,file);
}


void MainWindow::on_leerElArchivo_2_clicked()
{
    QString file="productos.dat";
    producto=f->leerAchivo(file);
}


void MainWindow::on_modificarButton_clicked()
{
    int codigo=ui->lineEdit_6->text().toInt();
    int cantidad=ui->lineEdit_7->text().toInt();
    for(int i=0;i<producto.size();i++){
        if(producto.at(i)->getCodigo()==codigo){
            producto.at(i)->cambiarStock(cantidad);
            break;
        }
    }
    QString file="productos.dat";
    f->guardarEnArchivo(producto,file);
}


void MainWindow::on_leerArhivoCSV_clicked()
{
    QString file="E:\archivo_excel\Libro1.xlsx";
    QFile archivo(file);

    if(!archivo.open(QIODevice::ReadOnly|QIODevice::Text)){
        qWarning()<<"No se puede abrir el archivo.";
        return;
    }
    QXmlStreamReader stream(&archivo);

    while(!stream.atEnd()){
        QString linea=stream.readElementText();
        QStringList valores=linea.split(",");
        double suma=0;
        for(int i=0;i<valores.size();i++){
            bool ok;
            double valor=valores[i].toDouble(&ok);
            if(ok){
                suma+=valor;
            }else{
                qWarning()<<"Error.";
            }
        }
        sumas.append(suma);
    }
    archivo.close();
}


void MainWindow::on_imprimirButton_3_clicked()
{
    QString info="";
    for(int i=0;i<sumas.size();i++){
        info+="Suma de numeros: "+QString::number(sumas.at(i));
    }
    ui->textEdit_3->setText(info);
}


void MainWindow::on_guardarArhivoCSV_2_clicked()
{

}


void MainWindow::on_agregar_clicked()
{

}

