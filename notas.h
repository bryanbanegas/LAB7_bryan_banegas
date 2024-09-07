#ifndef NOTAS_H
#define NOTAS_H
#include "QFile"
#include "QTextStream"
#include "QVector"
#include "QString"

class notas
{
private:
    QString nombre;
    double nota;
public:
    notas(QString& nombre, double nota)
        :nombre(nombre), nota(nota){}

    QString getNombre(){
        return nombre;
    }

    double getNota(){
        return nota;
    }

    void guardarEnArchivo(QVector<notas*>& estudiantes, QString& nombreDeArchivo){
        QFile archivo(nombreDeArchivo);
        if(archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
            QTextStream stream(&archivo);
            for(int i=0;i<estudiantes.size();i++){
                stream<<estudiantes.at(i)->getNombre()<<", "<<QString::number(estudiantes.at(i)->getNota())<<"\n";
            }
            archivo.close();
        }
    }

    void guardarEnArchivoSiPaso(QVector<notas*>& estudiantes, QString& nombreDeArchivo){
        QFile archivo(nombreDeArchivo);
        if(archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
            QTextStream stream(&archivo);
            for(int i=0;i<estudiantes.size();i++){
                if(estudiantes.at(i)->getNota()>=60){
                    stream<<estudiantes.at(i)->getNombre()<<", "<<QString::number(estudiantes.at(i)->getNota())<<", El estudiante paso."<<"\n";
                }else{
                    stream<<estudiantes.at(i)->getNombre()<<", "<<QString::number(estudiantes.at(i)->getNota())<<", El estudiante no paso."<<"\n";
                }
            }
            archivo.close();
        }
    }

    QVector<notas*> leerArchivo(QString& nombreDeArchivo){
        QFile archivo(nombreDeArchivo);
        QVector<notas*> estudiantes;
        if(archivo.open(QIODevice::ReadOnly|QIODevice::Text)){
            QTextStream stream(&archivo);
            while(!stream.atEnd()){
                QString linea=stream.readLine();
                QStringList valores=linea.split(", ");
                bool ok;
                QString nombre=valores[0];
                QString notaPrueba=valores[1];
                double nota=notaPrueba.toDouble(&ok);
                notas* nuevoEstudiante=new notas(nombre,nota);
                estudiantes.append(nuevoEstudiante);
            }
            archivo.close();
        }
        return estudiantes;
    }
};

#endif // NOTAS_H
