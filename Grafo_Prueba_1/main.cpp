#include <QCoreApplication>
#include <QDebug>
//Permite cear nuestro grafo
#include <QHash>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<QString, int> arista;
    QHash<QString, QHash<QString, int> > grafo;


    ///Iniciamos la modelación de las aristas que tienen conexióncon A
    ///
    arista.insert("B", 7);
    arista.insert("C", 3);
    arista.insert("D", 5);
    //Hacemos la conexion de A con todas las aristas que están conectados a el
    grafo.insert("A",arista);


    ///Iniciamos la modelación de las aristas que tienen conexión con B
    /// PRIEMRO HAREMOS UNA LIMPIEZA DE ARISTAS PARA QUE NO SE GUARDEN DOBLE POR ASÍ DECIRLO
    arista.clear();
    arista.insert("A", 7);
    grafo.insert("B", arista);

    ///Iniciamos la modelación de las aristas que tienen conexión con C
    /// PRIEMRO HAREMOS UNA LIMPIEZA DE ARISTAS PARA QUE NO SE GUARDEN DOBLE POR ASÍ DECIRLO
    arista.clear();
    arista.insert("A", 3);
    arista.insert("D", 6);
    grafo.insert("C", arista);

    ///Iniciamos la modelación de las aristas que tienen conexión con D
    /// PRIEMRO HAREMOS UNA LIMPIEZA DE ARISTAS PARA QUE NO SE GUARDEN DOBLE POR ASÍ DECIRLO
    arista.clear();
    arista.insert("A", 5);
    arista.insert("C", 6);
    grafo.insert("D", arista);

    //Ahora se mostrará el grafo en la terminal, pero se debe de ordenar debemos de tener un
    //iterador, bueno varios...
    ///De la misma manera que se crea o guarda el grafo, se debe de crear el iterador
    /// recorre la lista de nodos
    QHash<QString, QHash<QString, int> >::iterator gIt;
    for(gIt = grafo.begin(); gIt != grafo.end(); ++gIt)
    {
        QString llave = gIt.key();
        QHash<QString, int> vecinos = gIt.value();
        ///recorre la lista de vecinos
        QHash<QString, int>::iterator vIt;
        for(vIt = vecinos.begin(); vIt!= vecinos.end(); ++vIt)
        {
            qDebug() <<"(" <<llave<<"," <<vIt.key() << ")=" <<vIt.value() <<"\n";
        }

    }

    return a.exec();


}
