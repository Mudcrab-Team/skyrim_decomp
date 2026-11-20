// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12a27a0CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature12a27a0CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature12a27a0CopyableLayout : public ErasedSignature12a27a0CallableLayout {
public:
    ErasedSignature12a27a0CopyableLayout();
    ~ErasedSignature12a27a0CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature12a27a0CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
