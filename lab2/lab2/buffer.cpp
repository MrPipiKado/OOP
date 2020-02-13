#include "buffer.h"

string Buffer::getBuffer()
{
    string str = "";
    for(auto i = this->buffer.begin(); i!=this->buffer.end(); ++i)
    {
        str.append(i->toShow);
    }
    return str;
}

void Buffer::emptyBuffer()
{
    this->buffer.empty();
}

void Buffer::undoBuffer()
{
    this->buffer.pop_back();
}

void Buffer::addToBuffer(Piece piece)
{
    this->buffer.push_back(piece);
}

BufferController::BufferController(Buffer buffer, BufferView view):
    buffer(buffer),
    view(view)
{}
