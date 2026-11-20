// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused. Stamped as a twin of matched 0x1283250 (skyrim/papyrus/ErasedSignature1283250CallableLayout): source copied, names replaced by placeholders.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature1283220CallableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedCallableVptrStorageLayout.h"
namespace ResearchLayouts {
class ErasedSignature1283220CallableLayout {
public:
    ErasedSignature1283220CallableLayout();
    virtual ~ErasedSignature1283220CallableLayout() = default;
};
static_assert(sizeof(ErasedSignature1283220CallableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
