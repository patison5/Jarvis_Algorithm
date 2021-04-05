#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include "Dot.h"
#include "Sector.h"

using namespace std;

class App
{
    public:
        App();
        virtual ~App();

        vector <Sector*> _sectors;

        void initSectors(vector <Dot*> _dots);
        void showDotsInSectors();
        void showMBO();

    protected:

    private:
};

#endif // APP_H
