// Source exposure: binary-analysis (RTTI, invocation and complete construction/copy evidence).
// Code origin: original typed function-pointer declaration and ordinary constructors/defaulted destructors; no external implementation body or declaration reused.
// bnet::LogParams, CallableBase, CopyableCallable, ICallableBase, ICopyableCallable: EXE_RTTI
// LogCallback, LogCallableInterfaceLayout, LogCopyableInterfaceLayout, LogFunctionCallableLayout, CopyableLogFunctionCallableLayout, callback, Invoke: GUESS(medium) STANDIN
#pragma once
#include <cstddef>
#include "LogFunctionCallableLayout.h"
namespace ResearchLayouts {
class CopyableLogFunctionCallableLayout : public LogFunctionCallableLayout {
public:
    explicit CopyableLogFunctionCallableLayout(LogCallback callbackValue);
    ~CopyableLogFunctionCallableLayout() override = default;
};
static_assert(sizeof(CopyableLogFunctionCallableLayout) == 16, "typed callable representation");
static_assert(offsetof(CopyableLogFunctionCallableLayout, callback) == 8, "independently observed invocation member");
}
