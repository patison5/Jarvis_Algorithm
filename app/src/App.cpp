#include "App.h"

App::App() { }

App::~App() { }

void App :: initSectors(vector <Dot*> _dots) {

    for (auto dot = _dots.begin(); dot != _dots.end(); ++dot)
    {
        bool isAppended = false;

        int posX = (* dot) -> posX;
        int posY = (* dot) -> posY;

        for (auto sector = _sectors.begin(); sector != _sectors.end(); ++sector) {
            bool shouldAppend = false;
            vector <Dot*> _sectorDots = (* sector) -> _dots;

            for (auto sectorDot = _sectorDots.begin(); sectorDot != _sectorDots.end(); ++sectorDot) {
                int dotX = (* sectorDot) -> posX;
                int dotY = (* sectorDot) -> posY;

                if ((posX >= dotX - 1) && (posX <= dotX + 1) && (posY >= dotY - 1) && (posY <= dotY + 1)) {
                    shouldAppend = true;
                }
            }

            if (shouldAppend) {
                isAppended = true;
                (* sector) -> _dots.push_back((* dot));
                //cout << "appending to existed sector" << endl;
            }
        }

        if (!isAppended) {
            Sector *sec = new Sector();
            (*sec)._dots.push_back((* dot));
            _sectors.push_back(sec);
            //cout << "creating new sector and appending" << endl;
        }
    }

    for (int i = 0; i < _dots.size() - 1; i++) {
        int posX = (* _dots[i]).posX;
        int posY = (* _dots[i]).posX;
    }
}

void App :: showDotsInSectors() {
    for (auto sector = _sectors.begin(); sector != _sectors.end(); ++sector) {
        vector <Dot*> _sectorDots = (* sector) -> _dots;

        cout << endl << "Sector: " << endl;
        for (auto sectorDot = _sectorDots.begin(); sectorDot != _sectorDots.end(); ++sectorDot) {
            int dotX = (* sectorDot) -> posX;
            int dotY = (* sectorDot) -> posY;

            cout << dotX << ", " << dotY << endl;
        }
    }
}


void App :: showMBO () {
    for (auto sector = _sectors.begin(); sector != _sectors.end(); ++sector) {
        (* sector) -> JarvisMatch2();
    }
}
