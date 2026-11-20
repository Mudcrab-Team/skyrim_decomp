// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature1338d30CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature1338d30CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature1338d30CopyableLayout : public ErasedSignature1338d30CallableLayout {
public:
    ErasedSignature1338d30CopyableLayout();
    ~ErasedSignature1338d30CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature1338d30CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
