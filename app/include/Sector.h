#ifndef SECTOR_H
#define SECTOR_H
#include <iostream>
#include <vector>
#include "Dot.h"

using namespace std;

class Sector
{
    public:
        Sector();
        virtual ~Sector();

        vector <Dot*> _dots;
        vector <Dot*> _MBO;
        vector <int> _convex_hull;

        void JarvisMatch();
        void JarvisMatch2();

    protected:

    private:
        int triangle(Dot *A, Dot *B, Dot *C);
        bool isInside(Dot *A, Dot *B, const Dot *C);
};

#endif // SECTOR_H
