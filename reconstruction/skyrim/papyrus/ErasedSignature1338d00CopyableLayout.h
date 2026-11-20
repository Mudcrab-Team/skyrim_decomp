// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature1338d00CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature1338d00CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature1338d00CopyableLayout : public ErasedSignature1338d00CallableLayout {
public:
    ErasedSignature1338d00CopyableLayout();
    ~ErasedSignature1338d00CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature1338d00CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
