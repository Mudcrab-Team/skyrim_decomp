// Source exposure: binary-analysis (RTTI, invocation and complete construction/copy evidence).
// Code origin: original typed function-pointer declaration and ordinary constructors/defaulted destructors; no external implementation body or declaration reused.
// bnet::LogParams, CallableBase, CopyableCallable, ICallableBase, ICopyableCallable: EXE_RTTI
// LogCallback, LogCallableInterfaceLayout, LogCopyableInterfaceLayout, LogFunctionCallableLayout, CopyableLogFunctionCallableLayout, callback, Invoke: GUESS(medium) STANDIN
#pragma once
#include <cstddef>
#include "LogCopyableInterfaceLayout.h"
namespace ResearchLayouts {
class LogFunctionCallableLayout : public LogCopyableInterfaceLayout {
public:
    explicit LogFunctionCallableLayout(LogCallback callbackValue);
    ~LogFunctionCallableLayout() override = default;
    void Invoke(const bnet::LogParams&) override;
    LogCallback callback;
};
static_assert(sizeof(LogFunctionCallableLayout) == 16, "typed callable representation");
static_assert(offsetof(LogFunctionCallableLayout, callback) == 8, "independently observed invocation member");
}
