// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature129a590CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature129a590CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature129a590CopyableLayout : public ErasedSignature129a590CallableLayout {
public:
    ErasedSignature129a590CopyableLayout();
    ~ErasedSignature129a590CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature129a590CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
