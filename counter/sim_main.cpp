//VPI
//#include "Vstimulus.h"
#include "Vcounter.h"
#include "verilated.h"

//Smurf API
#include "smurf/smurf.h"
#include "smurf/emulator.h"

//System
#include <iostream>
#include <stdio.h>

using namespace std;

const int SIM_MAX_TICK = 20;

int main(int argc, char **argv)
{
    int count;
    VerilatedContext *contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    //Vstimulus *top = new Vstimulus { contextp };
    Vcounter *top = new Vcounter { contextp };

    for (count = 0; (!contextp->gotFinish()) && (count < SIM_MAX_TICK); count++)
    {
        //Set input wires.
        top->rst = 1;
        top->clk ^= 1;

        //Step once.
        top->eval();

        //Print output.
        printf("%d: %d\n", count, top->out);

    }

    delete top;
    delete contextp;

    return 0;
}
