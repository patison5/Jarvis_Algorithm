#include "Sector.h"

Sector::Sector() { }
Sector::~Sector() {}

int Sector :: triangle (Dot *A, Dot *B, Dot *C) {
    return (*A).posX * ((*B).posY - (*C).posY) + (*B).posX * ((*C).posY - (*A).posY) + (*C).posX * ((*A).posY - (*B).posY);
}

bool Sector :: isInside(Dot *A, Dot *B, const Dot *C)
{
    return ( (*A).posX <= (*B).posX && (*B).posX <= (*C).posX &&
             (*A).posY <= (*B).posY && (*B).posY <= (*C).posY);
}

void Sector :: JarvisMatch() {

    int base = 0;
    for (int i=1; i < _dots.size(); i++)
    {
        if ((* _dots[i]).posY < (* _dots[base]).posY)
            base = i;
        else
            if ((* _dots[i]).posY == (* _dots[base]).posY &&
                (* _dots[i]).posX <  (* _dots[base]).posX)
                base = i;
    }

    _MBO.push_back(_dots[base]);

    int first = base;
    int cur = base;
    do
    {
        int next = (cur + 1) % _dots.size();
        for (int i = 0; i < _dots.size(); i++)
        {
            int sign = triangle(_dots[cur],  _dots[next], _dots[i]);
            if (sign < 0)
                next = i;
            else if (sign == 0)
            {
               if (isInside( _dots[cur], _dots[next], _dots[i]))
                    next = i;
            }
        }
        cur = next;
        _MBO.push_back(_dots[next]);
    }
    while (cur != first);

    cout << endl << "MBO dots" << endl;
    for (auto sectorDot = this -> _MBO.begin(); sectorDot != this -> _MBO.end(); ++sectorDot) {
        int dotX = (* sectorDot) -> posX;
        int dotY = (* sectorDot) -> posY;
        cout << dotX << ", " << dotY  << endl;
    }
}
