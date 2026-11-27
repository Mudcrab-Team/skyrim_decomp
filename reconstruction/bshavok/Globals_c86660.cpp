// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00d3cef0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp:35
// 0xc86660 Func00d3cef0
#include "Globals_c86660.h"

void Func00d3cef0(Registry* registry)
{
    Conversion conversion;
    conversion.convert = Func00d3c400;
    conversion.create = Func00d3cfc0;
    conversion.copy = FlipAndDispatchCollector;
    conversion.destroy = Func00d3ac80;
    conversion.enabled = true;
    conversion.supported = false;
    registry->Func00cfbbe0(&conversion, 4, 1);
    conversion.convert = CreateD3C380Obj;
    conversion.create = Func00d3c440;
    conversion.copy = Func00d3cc00;
    conversion.destroy = Func00daf8e0;
    conversion.enabled = false;
    conversion.supported = false;
    registry->Func00cfbbe0(&conversion, 1, 4);
}
