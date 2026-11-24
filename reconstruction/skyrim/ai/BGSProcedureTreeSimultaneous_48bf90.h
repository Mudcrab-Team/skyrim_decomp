// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSProcedureTreeSimultaneous, BGSProcedureTreeSimultaneous::RunChildren, BGSProcedureTreeSimultaneous::children, BGSProcedureTreeSimultaneous::childCount, ProcedureNode, ProcedureNode::Vfunc11: GUESS(low)
#pragma once

#include <cstdint>

class ProcedureNode
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual bool Vfunc11();
};

class BGSProcedureTreeSimultaneous
{
public:
    void RunChildren();  // compared: 0x48bf90

    char unk00[0x10];
    ProcedureNode** children;
    char unk18[0x8];
    std::uint32_t childCount;
};
