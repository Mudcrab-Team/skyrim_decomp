// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: RegisterStaticCollisionAgent.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp:89
// 0xc79460 RegisterStaticCollisionAgent
#include "Globals_c79460.h"

void RegisterStaticCollisionAgent(D41FD0CollisionDispatcher* dispatcher)
{
    D41FD0AgentFuncs agentFuncs;
    agentFuncs.m_pCreateFunc = D41FD0CreateAgent;
    agentFuncs.m_pQueryPenetrationsFunc = D41FD0StaticGetPenetrations;
    agentFuncs.m_pGetPenetrationsFunc = D41FD0StaticGetClosestPoints;
    agentFuncs.m_pLinearCastFunc = D41FD0StaticLinearCast;
    agentFuncs.m_bIsFlipped = false;
    agentFuncs.m_bIsPredictive = true;
    dispatcher->registerCollisionAgent(agentFuncs, 19, 19);
}
