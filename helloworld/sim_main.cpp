//VPI
#include "Vstimulus.h"
#include "verilated.h"

//Smurf API
#include "smurf/smurf.h"
#include "smurf/emulator.h"

//System
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int count = 0;
    VerilatedContext *contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vstimulus *top = new Vstimulus { contextp };

    while (!contextp->gotFinish())
    {
        top->eval();
        cout << count << endl;
    }

    delete top;
    delete contextp;

    return 0;
}
