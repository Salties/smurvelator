#!/usr/bin/python3

import smurf

core = smurf.Core(ver=2)

core.NewComponent('clk', 'BOOL')
core.NewComponent('rst', 'BOOL')
core.NewComponent('out', 'INT32')

core.Save('counter.json')
