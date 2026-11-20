// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12d2310CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature12d2310CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature12d2310CopyableLayout : public ErasedSignature12d2310CallableLayout {
public:
    ErasedSignature12d2310CopyableLayout();
    ~ErasedSignature12d2310CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature12d2310CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
