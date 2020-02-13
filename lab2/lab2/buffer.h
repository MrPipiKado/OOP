#ifndef BUFFER_H
#define BUFFER_H


#include <QLabel>
#include <QString>

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Buffer;
class Piece
{
    friend Buffer;
public:
private:
  string toShow;
};

class Buffer
{
public:
    string getBuffer();
    inline void emptyBuffer();
    inline void undoBuffer();
    inline void addToBuffer(Piece);

private:
    vector<Piece> buffer;
    string result;
};

class BufferView
{
public:
    void printResult(string result, QLabel lable)
    {
        lable.setText(QString::fromStdString(result));
    }
};

class BufferController
{
public:
    BufferController(Buffer, BufferView);
private:
    Buffer buffer;
    BufferView view;
};
#endif // BUFFER_H
