// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature129a5c0CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature129a5c0CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature129a5c0CopyableLayout : public ErasedSignature129a5c0CallableLayout {
public:
    ErasedSignature129a5c0CopyableLayout();
    ~ErasedSignature129a5c0CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature129a5c0CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
