#ifndef CBBOX_H
#define CBBOX_H

class CBBox
{
public:
    int width = 0;
    int height = 0;
    CBBox() {};
    CBBox(int w, int h) : width(w), height(h) {};
};

#endif