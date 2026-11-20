// Source exposure: binary-analysis (RTTI, invocation and complete construction/copy evidence).
// Code origin: original typed function-pointer declaration and ordinary constructors/defaulted destructors; no external implementation body or declaration reused.
// bnet::LogParams, CallableBase, CopyableCallable, ICallableBase, ICopyableCallable: EXE_RTTI
// LogCallback, LogCallableInterfaceLayout, LogCopyableInterfaceLayout, LogFunctionCallableLayout, CopyableLogFunctionCallableLayout, callback, Invoke: GUESS(medium) STANDIN
#pragma once
namespace bnet { struct LogParams; }
namespace ResearchLayouts {
using LogCallback = void (*)(const bnet::LogParams&);
class LogCallableInterfaceLayout {
public:
    LogCallableInterfaceLayout();
    virtual ~LogCallableInterfaceLayout() = default;
    virtual void Invoke(const bnet::LogParams&) = 0;
};
static_assert(sizeof(LogCallableInterfaceLayout) == 8, "fieldless invocation interface");
}
