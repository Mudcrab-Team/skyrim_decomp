// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12add90CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature12add90CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature12add90CopyableLayout : public ErasedSignature12add90CallableLayout {
public:
    ErasedSignature12add90CopyableLayout();
    ~ErasedSignature12add90CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature12add90CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
