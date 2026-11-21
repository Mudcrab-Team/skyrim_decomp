// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused. Stamped as a twin of matched 0x1283250 (skyrim/papyrus/ErasedSignature1283250CallableLayout): source copied, names replaced by placeholders.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature141dbd0CallableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedCallableVptrStorageLayout.h"
namespace ResearchLayouts {
class ErasedSignature141dbd0CallableLayout {
public:
    ErasedSignature141dbd0CallableLayout();
    virtual ~ErasedSignature141dbd0CallableLayout() = default;
};
static_assert(sizeof(ErasedSignature141dbd0CallableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
