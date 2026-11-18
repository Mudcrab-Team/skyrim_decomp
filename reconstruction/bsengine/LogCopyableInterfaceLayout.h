// Source exposure: binary-analysis (RTTI, invocation and complete construction/copy evidence).
// Code origin: original typed function-pointer declaration and ordinary constructors/defaulted destructors; no external implementation body or declaration reused.
// bnet::LogParams, CallableBase, CopyableCallable, ICallableBase, ICopyableCallable: EXE_RTTI
// LogCallback, LogCallableInterfaceLayout, LogCopyableInterfaceLayout, LogFunctionCallableLayout, CopyableLogFunctionCallableLayout, callback, Invoke: GUESS(medium) STANDIN
#pragma once
#include "LogCallableInterfaceLayout.h"
namespace ResearchLayouts {
class LogCopyableInterfaceLayout : public LogCallableInterfaceLayout {
public:
    LogCopyableInterfaceLayout();
    ~LogCopyableInterfaceLayout() override = default;
};
static_assert(sizeof(LogCopyableInterfaceLayout) == 8, "copy interface adds no storage");
}
