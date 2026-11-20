// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12bc620CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature12bc620CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature12bc620CopyableLayout : public ErasedSignature12bc620CallableLayout {
public:
    ErasedSignature12bc620CopyableLayout();
    ~ErasedSignature12bc620CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature12bc620CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
