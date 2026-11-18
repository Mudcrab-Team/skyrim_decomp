// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12ade20CallableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedCallableVptrStorageLayout.h"
namespace ResearchLayouts {
class ErasedSignature12ade20CallableLayout {
public:
    ErasedSignature12ade20CallableLayout();
    virtual ~ErasedSignature12ade20CallableLayout() = default;
};
static_assert(sizeof(ErasedSignature12ade20CallableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
