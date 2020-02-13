#ifndef BOOKFILE_H
#define BOOKFILE_H
#include <QFile>

struct recType   // структура записи для одного абонента
{
    QString author, name, publisher, yearOfPublication, numberOfCopies;
};

class bookFile
{
    QFile *f;    // указатель на объект класса QFile
    bool k1,k2,k3,k4,ff; // ключи поиска
public:
    int a[50];
    recType r;  // буфер ввода-вывода
    bookFile();  // конструктор
    ~bookFile(); // деструктор
    bool addRec(recType r); // добавление записи в файл
    bool readRec();	    // чтение записи из файда
    bool findFirst(const recType r1, int p, QString number); // поиск первой
    bool findNext(const recType r1, int p, QString number);
    int *findYears(int &size);
};

#endif // BOOKFILE_H
