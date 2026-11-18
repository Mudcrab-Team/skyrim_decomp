// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature1283250CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature1283250CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature1283250CopyableLayout : public ErasedSignature1283250CallableLayout {
public:
    ErasedSignature1283250CopyableLayout();
    ~ErasedSignature1283250CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature1283250CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
