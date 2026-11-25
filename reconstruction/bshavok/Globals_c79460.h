// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// RegisterStaticCollisionAgent: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// Globals: GUESS(low); placeholder name
#pragma once

struct D41FD0AgentFuncs;
struct D41FD0CollisionDispatcher;


typedef void(* D41FD0Func)();

struct D41FD0AgentFuncs
{
    D41FD0Func m_pCreateFunc;
    D41FD0Func m_pQueryPenetrationsFunc;
    D41FD0Func m_pGetPenetrationsFunc;
    D41FD0Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

struct D41FD0CollisionDispatcher
{
    void registerCollisionAgent(D41FD0AgentFuncs& f, int typeA, int typeB);
};

void D41FD0CreateAgent();
void D41FD0StaticGetPenetrations();
void D41FD0StaticGetClosestPoints();
void D41FD0StaticLinearCast();

struct Globals
{
};
