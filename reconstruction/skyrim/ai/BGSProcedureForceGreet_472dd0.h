// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSProcedureDialogueActivate.cpp:11
// BGSProcessContext, BGSVisitProceduresInitActorLocation, BGSVisitProceduresInitActorLocation::SetInitialLocation, IAIWorldLocation: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; used here for BGSProcedureForceGreet
// BGSProcedureForceGreet: GUESS(low) EXE_RTTI
// BGSProcedureForceGreet::InitActorLocation, BGSProcedureForceGreet::InitExecState: GUESS(low); named after the sibling method with the same shape
// BGSProcedureForceGreet::Unk_01, BGSProcedureForceGreet::Unk_02, BGSProcedureForceGreet::Unk_03, BGSProcedureForceGreet::Unk_04, BGSProcedureForceGreet::Unk_05, BGSProcedureForceGreet::Unk_06, BGSProcedureForceGreet::Unk_07, BGSProcedureForceGreet::Unk_08, BGSProcessContext::unknown00, ExecStateHolder, ExecStateHolder::unknown00, ExecStateHolder::location: GUESS(low)
#pragma once

#include <cstdint>

class IAIWorldLocation;

class ExecStateHolder
{
public:
    void* unknown00;              // 00
    IAIWorldLocation* location;   // 08
};

class BGSProcessContext
{
public:
    void* unknown00;              // 00
    ExecStateHolder* execState;   // 08
};

class BGSVisitProceduresInitActorLocation
{
public:
    void SetInitialLocation(const IAIWorldLocation* a_location);
};

class BGSProcedureForceGreet
{
public:
    virtual ~BGSProcedureForceGreet();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void InitExecState(BGSProcessContext& a_context) const;  // 09
    virtual void InitActorLocation(BGSProcessContext& a_context, BGSVisitProceduresInitActorLocation& a_visitor) const;  // 0A
};
