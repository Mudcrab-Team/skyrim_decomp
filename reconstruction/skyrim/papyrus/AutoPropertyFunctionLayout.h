// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// AutoPropertyFunctionLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// BSScript::Internal::AutoPropGetFunction, BSScript::Internal::AutoPropSetFunction: EXE_RTTI
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
#include "NativeFunctionLayout.h"
namespace ResearchLayouts {
// objectName, functionName, propertyType, propertyIndex: GUESS(medium) STANDIN; physical fields, meanings unverified.
class AutoPropertyFunctionLayout : public ScriptFunctionLayout { public: ~AutoPropertyFunctionLayout();
    ScriptStringLayout objectName;
    ScriptStringLayout functionName;
    ScriptTypeLayout propertyType;
    std::uint32_t propertyIndex;
};
static_assert(sizeof(AutoPropertyFunctionLayout)==48,"represented size");
static_assert(offsetof(AutoPropertyFunctionLayout,objectName)==16,"observed field offset");
static_assert(offsetof(AutoPropertyFunctionLayout,functionName)==24,"observed field offset");
static_assert(offsetof(AutoPropertyFunctionLayout,propertyType)==32,"observed field offset");
static_assert(offsetof(AutoPropertyFunctionLayout,propertyIndex)==40,"observed field offset");
}
