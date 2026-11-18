// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12bc620CallableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedCallableVptrStorageLayout.h"
namespace ResearchLayouts {
class ErasedSignature12bc620CallableLayout {
public:
    ErasedSignature12bc620CallableLayout();
    virtual ~ErasedSignature12bc620CallableLayout() = default;
};
static_assert(sizeof(ErasedSignature12bc620CallableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
