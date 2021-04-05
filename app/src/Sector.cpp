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
    //cout << "jarvising sector" << endl;
    int N = this -> _dots.size();
    int firstIndex = 0;
    int j = 0;

    Dot * first = _dots[0];

    for (auto sectorDot = this -> _dots.begin(); sectorDot != this -> _dots.end(); ++sectorDot) {
        int dotX = (* sectorDot) -> posX;
        int dotY = (* sectorDot) -> posY;

        if ((*first).posY > dotY)  {
            first = (* sectorDot);
            firstIndex = j;
        }
        else if ( ((*first).posY == dotY) &&  ((*first).posX > dotX) ) {
            first = (* sectorDot);
            firstIndex = j;
        }

        j++;
        //cout << dotX << ", " << dotY << endl;
    }

    cout << "Leftest dot is " << endl;
    cout << (* first).posX << ", " << (* first).posY  << " : " << firstIndex << endl;

    _MBO.push_back(first);

    Dot * current = first;
    int currentIndex = firstIndex;

    do {
        int nextIndex = (currentIndex + 1) % _dots.size();

        for (int i = 0; i < _dots.size(); i++)
        {
            int sign = triangle(_dots[currentIndex], _dots[nextIndex], _dots[i]);
            if (sign < 0)
                nextIndex = i;
            else if (sign == 0)
            {
                if (isInside(_dots[currentIndex], _dots[nextIndex], _dots[i]))
                    nextIndex = i;
            }
        }
        currentIndex = nextIndex;
        _MBO.push_back(_dots[nextIndex]);

    } while (first != current);


    cout << endl << "MBO dots" << endl;
    for (auto sectorDot = this -> _MBO.begin(); sectorDot != this -> _MBO.end(); ++sectorDot) {
        int dotX = (* sectorDot) -> posX;
        int dotY = (* sectorDot) -> posY;
        cout << dotX << ", " << dotY  << endl;
    }
}

void Sector :: JarvisMatch2() {

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

    _convex_hull.push_back(base);

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
        _convex_hull.push_back(next);
    }
    while (cur != first);

    cout << endl << "Filtered dots:" << endl;
    for (int i = 0; i < _convex_hull.size(); i++) {
        cout << "(" << (*_dots[_convex_hull[i]]).posX << "," << (*_dots[_convex_hull[i]]).posY << ")" << endl;
    }
}
