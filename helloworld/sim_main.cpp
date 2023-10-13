#include "Vour.h"
#include "verilated.h"
#include <iostream>
#include "smurf/smurf.h"
#include "smurf/emulator.h"

using namespace std;

int main(int argc, char** argv)
{
    int count = 0;
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vour* top = new Vour{contextp};

    while(!contextp->gotFinish())
    {
        top->eval();
        cout<<count<<endl;
    }

    delete top;
    delete contextp;

    return 0;
}
