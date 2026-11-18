// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature1283310CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature1283310CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature1283310CopyableLayout : public ErasedSignature1283310CallableLayout {
public:
    ErasedSignature1283310CopyableLayout();
    ~ErasedSignature1283310CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature1283310CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
