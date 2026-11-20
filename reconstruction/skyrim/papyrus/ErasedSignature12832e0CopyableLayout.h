// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12832e0CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature12832e0CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature12832e0CopyableLayout : public ErasedSignature12832e0CallableLayout {
public:
    ErasedSignature12832e0CopyableLayout();
    ~ErasedSignature12832e0CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature12832e0CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
