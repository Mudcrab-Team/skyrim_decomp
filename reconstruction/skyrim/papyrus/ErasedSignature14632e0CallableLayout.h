// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused. Stamped as a twin of matched 0x1283250 (skyrim/papyrus/ErasedSignature1283250CallableLayout): source copied, names replaced by placeholders.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature14632e0CallableLayout: GUESS(medium) STANDIN
// Adapted bodies: none
#pragma once
#include "ErasedCallableVptrStorageLayout.h"
namespace ResearchLayouts {
class ErasedSignature14632e0CallableLayout {
public:
    ErasedSignature14632e0CallableLayout();
    virtual ~ErasedSignature14632e0CallableLayout() = default;
};
static_assert(sizeof(ErasedSignature14632e0CallableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
