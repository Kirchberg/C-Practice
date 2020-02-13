#include "bookfile.h"
#include "mainform.h"
#include <QMessageBox>

bookFile::bookFile()  // конструктор
{
    f = new QFile("book.txt"); // создаем объект-файл
    f->open(QFile::ReadWrite); // открываем файл
    for (int i = 0; i < 20;i++)
    {
        a[i] = 0;
    }
 }
bookFile::~bookFile()   // деструктор
{
    f->close();        // закрываем файл
    delete f;                        // освобождаем память
}
bool bookFile::addRec(recType r)
{
    f->seek(f->size()); // переходим на конец файла
    QDataStream out(f); // связываем с файлом поток вывода
    out << r.author << r.name << r.publisher << r.yearOfPublication << r.numberOfCopies;// выводим данные в файл
    return true;
}
bool bookFile::readRec()
{
    QDataStream in(f); // связываем с файлом поток ввода
    if (in.atEnd())
        return false;
    else
    {
        in >> r.author >> r.name >> r.publisher >> r.yearOfPublication >> r.numberOfCopies;
        return true;
    }
}
bool bookFile::findFirst(const recType r1, int i, QString number)
{
    switch (i)
    {
        case 1:
            {
                k1=(r1.author == "");   // устанавливаем два ключа поиска
                ff=false;   // устанавливаем ключ поиска «запись не найдена»
                f->reset();
                bool fff = readRec();
                while(fff &&(!ff))
                {
                    k3=(r1.author==r.author);  //строим еще два ключа поиска
                      if (!k1 && k3)
                        ff=true; // ключ поиска «запись найдена»
                    else fff=readRec();
                }
                break;
            }

        case 2:
            {
                ff=false;   // устанавливаем ключ поиска «запись не найдена»
                f->reset();
                bool fff = readRec();
                while(fff &&(!ff))
                {
                      if ((number.toInt() < r.numberOfCopies.toInt()))
                        ff = true; // ключ поиска «запись найдена»
                    else fff=readRec();
                }
                break;
            }

        case 3:
            {
                k1=(r1.publisher == "");   // устанавливаем два ключа поиска
                k2=(r1.yearOfPublication == "");
                ff=false;   // устанавливаем ключ поиска «запись не найдена»
                f->reset();
                bool fff = readRec();
                while(fff &&(!ff))
                {
                    k3=(r1.publisher==r.publisher);  //строим еще два ключа поиска
                      k4=(r1.yearOfPublication==r.yearOfPublication);
                      if ((!k1 && !k2 && k3 && k4)||
                         (!k1 && k2 && k3)||
                         (k1 && !k2 && k4))
                        ff=true; // ключ поиска «запись найдена»
                    else fff=readRec();
                }
                break;
            }
    }
    return ff; // возвращаем ключ поиска
}
bool bookFile::findNext(const recType r1, int i, QString number)
{
    ff=false;   // ключ поиска «запись не найдена»
    switch (i)
    {
        case 1:
            {
                bool fff = readRec();
                while((!ff) && fff)
                {
                    k3 = (r1.author == r.author);//строим еще два ключа поиска
                      if ((!k1 && k3))
                        ff=true;     // ключ поиска «запись найдена»
                    else fff = readRec();
                }
                break;
            }

        case 2:
            {
                bool fff = readRec();
                while((!ff) && fff)
                {
                      if ((number.toInt() < r.numberOfCopies.toInt()) )
                        ff = true;     // ключ поиска «запись найдена» //что-то тут исправить
                    else fff = readRec();
                }
                break;
            }

        case 3:
            {
                bool fff = readRec();
                while((!ff) && fff)
                {
                    k3=(r1.publisher == r.publisher);//строим еще два ключа поиска
                    k4=(r1.yearOfPublication == r.yearOfPublication);
                      if (!k1 && !k2 && k3 && k4)
                        ff=true;     // ключ поиска «запись найдена»
                    else fff=readRec();
                }
                break;
            }
    }
    return ff; // возвращаем ключ поиска
}

int *bookFile::findYears(int &size)
{
    size = 0;
    f->reset();
    bool fff = readRec();
    while(fff)
    {
        a[size] = r.yearOfPublication.toInt();
        fff = readRec();
        size++;
    }
    return a;
}
