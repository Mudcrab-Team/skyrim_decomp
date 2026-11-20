// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12addc0CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature12addc0CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature12addc0CopyableLayout : public ErasedSignature12addc0CallableLayout {
public:
    ErasedSignature12addc0CopyableLayout();
    ~ErasedSignature12addc0CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature12addc0CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
