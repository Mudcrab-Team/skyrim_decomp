// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature129e770CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature129e770CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature129e770CopyableLayout : public ErasedSignature129e770CallableLayout {
public:
    ErasedSignature129e770CopyableLayout();
    ~ErasedSignature129e770CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature129e770CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
