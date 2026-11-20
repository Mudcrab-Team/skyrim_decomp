// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12cdf40CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature12cdf40CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature12cdf40CopyableLayout : public ErasedSignature12cdf40CallableLayout {
public:
    ErasedSignature12cdf40CopyableLayout();
    ~ErasedSignature12cdf40CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature12cdf40CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
