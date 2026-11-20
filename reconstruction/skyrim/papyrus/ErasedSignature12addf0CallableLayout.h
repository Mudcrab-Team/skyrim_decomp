// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused. Stamped as a twin of matched 0x1283250 (skyrim/papyrus/ErasedSignature1283250CallableLayout): source copied, names replaced by placeholders.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12addf0CallableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedCallableVptrStorageLayout.h"
namespace ResearchLayouts {
class ErasedSignature12addf0CallableLayout {
public:
    ErasedSignature12addf0CallableLayout();
    virtual ~ErasedSignature12addf0CallableLayout() = default;
};
static_assert(sizeof(ErasedSignature12addf0CallableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
