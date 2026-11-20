// Source exposure: binary-analysis (RTTI, invocation and complete construction/copy evidence).
// Code origin: original typed function-pointer declaration and ordinary constructors/defaulted destructors; no external implementation body or declaration reused.
// bnet::LogParams, CallableBase, CopyableCallable, ICallableBase, ICopyableCallable: EXE_RTTI
// LogCallback, LogCallableInterfaceLayout, LogCopyableInterfaceLayout, LogFunctionCallableLayout, CopyableLogFunctionCallableLayout, callback, Invoke: GUESS(medium) STANDIN
// callbackValue: GUESS(low)
// 0x1259b00 CopyableLogFunctionCallableLayout scalar deleting destructor
void operator delete(void*, unsigned __int64) noexcept;
#include "CopyableLogFunctionCallableLayout.h"
namespace ResearchLayouts {
CopyableLogFunctionCallableLayout::CopyableLogFunctionCallableLayout(LogCallback callbackValue) : LogFunctionCallableLayout(callbackValue) {}
}
