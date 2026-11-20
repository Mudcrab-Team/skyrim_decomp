// Source exposure: binary-analysis (RTTI, invocation and complete construction/copy evidence).
// Code origin: original typed function-pointer declaration and ordinary constructors/defaulted destructors; no external implementation body or declaration reused.
// bnet::LogParams, CallableBase, CopyableCallable, ICallableBase, ICopyableCallable: EXE_RTTI
// LogCallback, LogCallableInterfaceLayout, LogCopyableInterfaceLayout, LogFunctionCallableLayout, CopyableLogFunctionCallableLayout, callback, Invoke: GUESS(medium) STANDIN
// 0x1259ce0 LogCallableInterfaceLayout scalar deleting destructor
void operator delete(void*, unsigned __int64) noexcept;
#include "LogCallableInterfaceLayout.h"
namespace ResearchLayouts {
LogCallableInterfaceLayout::LogCallableInterfaceLayout() = default;
}
