// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature129e740CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature129e740CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature129e740CopyableLayout : public ErasedSignature129e740CallableLayout {
public:
    ErasedSignature129e740CopyableLayout();
    ~ErasedSignature129e740CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature129e740CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
