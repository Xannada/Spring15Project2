#include "mainwindow.h"
#include <QApplication>
#include "heap.h"
#include "item.h"
#include "shoppingdisplay.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    //w.show();

    Item q;
    q.set(5,25.99,"Baseball cap","Fenway Park");
    Item b;
    b.set(1,35.35,"Baseball bat","Dodger Stadium");
    Item c;
    c.set(2,12.99,"Team pennant","Rogers Centre");
    Item d;
    d.set(7,19.99,"Autographed baseball","Rogers Centre");
    Item e;
    e.set(7,19.99,"Autographed baseball","Rogers Centre");
    Item f;
    f.set(7,19.99,"Autographed baseball","Rogers Centre");


    Heap<Item, QString> heap;
    heap.insert(q, q.type);
    heap.insert(b, b.type);
    heap.insert(c, c.type);
    heap.insert(d, d.type);
    heap.insert(e, e.type);
    heap.insert(f, f.type);

    Heap<Item, float> fHeap;
    fHeap.insert(q, q.price);
    fHeap.insert(b, b.price);
    fHeap.insert(b, b.price);
    fHeap.insert(b, b.price);
    fHeap.insert(f, f.price);
    fHeap.insert(e, e.price);

    ShoppingDisplay sd(&w, 6, &heap);
 //   sd.populateTable(fHeap);
    sd.show();

//    int choice = 1;
//    qDebug() << "Choose a sort type\n"
//             << "1. Type\n"
//             << "2. Stadium\n"
//             << "3. Price\n"
//             << "4. Quantity\n"
//             << "5. EXIT\n"
//             << "Enter choice: "
//             << choice;

//    while(choice <= 4){
//        switch(choice){
//        case 1 :   {Heap<Item, QString> copyHeap;
//                    copyHeap = heap;
//                    copyHeap.draw();}
//                    break;
//        case 2:    {Heap<Item, QString> copyHeap;
//                    Heap<Item, QString> stadiumHeap;
//                    copyHeap = heap;
//                    while(copyHeap.size() > 0){
//                        stadiumHeap.insert(copyHeap.min(), copyHeap.min().stadium);
//                        copyHeap.removeMin();
//                    }
//                    stadiumHeap.draw();}
//                    break;
//        case 3:    {Heap<Item, QString> copyHeap;
//                    Heap<Item, float>   priceHeap;
//                    copyHeap = heap;
//                    while(copyHeap.size() > 0){
//                        priceHeap.insert(copyHeap.min(), copyHeap.min().price);
//                        copyHeap.removeMin();
//                    }
//                    priceHeap.draw();}
//                    break;
//        case 4:    {Heap<Item, QString> copyHeap;
//                    Heap<Item, float>   quantityHeap;
//                    copyHeap = heap;
//                    while(copyHeap.size() > 0){
//                        quantityHeap.insert(copyHeap.min(), copyHeap.min().quantity);
//                        copyHeap.removeMin();
//                    }
//                    quantityHeap.draw();}
//                    break;
//        default :
//            break;
//        }
//        qDebug() << "Choose a sort type\n"
//                 << "1. Type\n"
//                 << "2. Stadium\n"
//                 << "3. Price\n"
//                 << "4. Quantity\n"
//                 << "5. EXIT\n"
//                 << "Enter choice: "
//                 << ++choice;

//    }


    return a.exec();
}
