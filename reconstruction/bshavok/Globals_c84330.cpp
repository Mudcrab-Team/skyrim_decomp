// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: RegisterHandlers.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp:67
// 0xc84330 RegisterHandlers
#include "Globals_c84330.h"

void RegisterHandlers(Registry* registry) {
    void Func009c4740();
    void Func009c47e0();
    void Func009c5400();
    void Func00a3ab70();
    HandlerSet handlers;
    handlers.m_cFlagA=0;
    handlers.m_cFlagB=0;
    handlers.m_pfnFirst=Func009c4740;
    handlers.m_pfnSecond=Func009c47e0;
    handlers.m_pfnThird=Func009c5400;
    handlers.m_pfnFourth=Func00a3ab70;
    registry->Func00cfbbe0(&handlers,5,5);
}
