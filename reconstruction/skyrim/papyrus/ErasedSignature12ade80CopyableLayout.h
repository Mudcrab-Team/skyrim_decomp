// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12ade80CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature12ade80CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature12ade80CopyableLayout : public ErasedSignature12ade80CallableLayout {
public:
    ErasedSignature12ade80CopyableLayout();
    ~ErasedSignature12ade80CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature12ade80CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
