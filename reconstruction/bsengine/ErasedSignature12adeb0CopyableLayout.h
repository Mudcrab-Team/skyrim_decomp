// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12adeb0CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature12adeb0CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature12adeb0CopyableLayout : public ErasedSignature12adeb0CallableLayout {
public:
    ErasedSignature12adeb0CopyableLayout();
    ~ErasedSignature12adeb0CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature12adeb0CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
