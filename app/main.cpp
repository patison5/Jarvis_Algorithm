#include <iostream>
#include <vector>
#include "Dot.h"
#include "Sector.h"
#include "App.h"

using namespace std;

int main()
{
    int N = 10;
    int M = 10;

    vector <Dot*> _dots;

    _dots.push_back( new Dot(1,2) );
    _dots.push_back( new Dot(2,1) );
    _dots.push_back( new Dot(2,2) );
    _dots.push_back( new Dot(3,1) );
    _dots.push_back( new Dot(3,2) );
    _dots.push_back( new Dot(4,0) );

    _dots.push_back( new Dot(1,7) );
    _dots.push_back( new Dot(2,6) );
    _dots.push_back( new Dot(2,7) );
    _dots.push_back( new Dot(2,8) );
    _dots.push_back( new Dot(3,6) );
    _dots.push_back( new Dot(3,7) );

    cout << endl << "All of dots" << endl;
    for (auto dot = _dots.begin(); dot != _dots.end(); ++dot) {
        int dotX = (* dot) -> posX;
        int dotY = (* dot) -> posY;
        cout << "(" << dotX << ", " << dotY << ")" << endl;
    }

    App app;
    app.initSectors(_dots);
    app.showDotsInSectors();
    app.showMBO();

    return 0;
}
