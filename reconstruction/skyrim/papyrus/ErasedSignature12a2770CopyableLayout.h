// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedSignature12a2770CopyableLayout: GUESS(medium) STANDIN
#pragma once
#include "ErasedSignature12a2770CallableLayout.h"
namespace ResearchLayouts {
class ErasedSignature12a2770CopyableLayout : public ErasedSignature12a2770CallableLayout {
public:
    ErasedSignature12a2770CopyableLayout();
    ~ErasedSignature12a2770CopyableLayout() override = default;
};
static_assert(sizeof(ErasedSignature12a2770CopyableLayout) == sizeof(ErasedCallableVptrStorageLayout), "independently evidenced primary interface prefix");
}
