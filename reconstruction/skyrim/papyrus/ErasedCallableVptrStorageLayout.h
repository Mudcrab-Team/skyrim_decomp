// Source exposure: binary-analysis (independent RTTI and concrete stored-value boundary evidence).
// Code origin: original narrowed physical interface declarations and defaulted special members; no external implementation body or declaration reused.
// ICallableBase, ICopyableCallable: EXE_RTTI
// ErasedCallableVptrStorageLayout, dispatchTable: GUESS(medium) STANDIN
#pragma once
#include <cstddef>
namespace ResearchLayouts {
struct ErasedCallableVptrStorageLayout { const void* const* dispatchTable; };
static_assert(sizeof(ErasedCallableVptrStorageLayout) == 8, "observed fieldless interface prefix");
static_assert(offsetof(ErasedCallableVptrStorageLayout, dispatchTable) == 0, "primary vptr storage");
}
