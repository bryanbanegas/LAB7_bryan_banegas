#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#include "QFile"
#include "QDataStream"
#include "QVector"
#include "QString"

class productos
{
private:
    int codigo;
    QString nombre;
    double precio;
    int cantidad;
public:
    productos(int codigo, QString& nombre, double precio, int cantidad)
        :codigo(codigo), nombre(nombre), precio(precio), cantidad(cantidad){}

    int getCodigo(){
        return codigo;
    }

    QString getInfo(){
        QString info="Codigo: "+QString::number(codigo)+", Nombre: "+nombre+", Precio: "+QString::number(precio)+", Cantidad: "+QString::number(cantidad)+"\n";
        return info;
    }

    void cambiarStock(int nuevaCantidad){
        cantidad=nuevaCantidad;
    }

    friend QDataStream& operator<<(QDataStream& out, productos& p){
        out<<p.codigo<<p.nombre<<p.precio<<p.cantidad;
        return out;
    }

    friend QDataStream& operator>>(QDataStream& in, productos& p) {
        in >> p.codigo >> p.nombre >> p.precio >> p.cantidad;  // Deserializar atributos
        return in;
    }

    void guardarEnArchivo(QVector<productos*> producto, QString& nombreArchivo){
        QFile archivo(nombreArchivo);

        if(!archivo.open(QIODevice::WriteOnly)){
            qWarning()<<"No se puede abrir el archivo.";
            return;
        }

        QDataStream stream(&archivo);
        for(productos* p:producto){
            stream<<*p;
        }
        archivo.close();
    }

    QVector<productos*> leerAchivo(QString& nombreArchivo){
        QFile archivo(nombreArchivo);
        QVector<productos*> producto;

        if(!archivo.open(QIODevice::ReadOnly)){
            qWarning()<<"No se puede abrir el archivo";
            return producto;
        }

        QDataStream stream(&archivo);
        while(!stream.atEnd()){
            int codigo=0;
            QString nombre="";
            double precio=0;
            int cantidad=0;
            productos* nuevoProducto=new productos(codigo,nombre,precio,cantidad);
            stream>>*nuevoProducto;
            producto.append(nuevoProducto);
        }

        archivo.close();
        return producto;
    }
};

#endif // PRODUCTOS_H
