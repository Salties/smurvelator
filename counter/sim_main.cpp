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
    //Simulation init.
    int count;
    VerilatedContext *contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vcounter *top = new Vcounter { contextp };

    //Smurf init.
    Smurf *smurf = InitSmurf("counter.json",
                             "/tmp/counter.smurf.trace",
                             SMURF_TRACE_MODE_CREATE);
    SmurfBind(smurf, "clk", &top->clk);
    SmurfBind(smurf, "rst", &top->rst);
    SmurfBind(smurf, "out", &top->out); //TODO: Glitched.

    //Simulate up to SIM_MAX_TICK ticks.
    for (count = 0; (!contextp->gotFinish()) && (count < SIM_MAX_TICK); count++)
    {
        //Set input wires.
        top->rst = 1;
        top->clk ^= 1;

        if(4 == count)          //Rest the counter once.
        {
            top->rst = 0;
        }

        //Step once.
        top->eval();

        //Sync and write frame.
        SmurfSync(smurf);
        SmurfWrite(smurf);

        //Print output.
        printf("%d: %d\n", count, top->out);

    }

    delete top;
    delete contextp;

    return 0;
}
