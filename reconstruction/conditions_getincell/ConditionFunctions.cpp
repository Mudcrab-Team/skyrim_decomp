// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// TESForm fields and TESObjectREFR members: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from public headers.
// names: GUESS(low); names and signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ConditionFunctions, ConditionFunctions::GetInCell: GUESS(low); the static source container and original signature are unverified.
// 0x3334e0 Condition::GetInCell
#include "ConditionFunctions.h"
#include "../fo4p198c_bound/TESForm.h"
struct HandleRef { void* vtable; unsigned int refCount, pad; };
struct AnimationSink { void* vtable; };
struct AnimationHolder { void* vtable; };
struct Point3 { float x, y, z; };
struct RefData { void* object; Point3 angle, position; };
class TESObjectCELL;
class TESObjectREFR : public TESForm, public HandleRef, public AnimationSink, public AnimationHolder {
public:
    RefData data;
    TESObjectCELL* parentCell;
};
extern void* conditionLogger;
extern const char cellLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetInCell(TESObjectREFR* reference, TESForm* parameter, TESForm* other, double* result)
{
    *result = 0.0;
    TESObjectCELL* cell = nullptr;
    if (parameter && parameter->formType == static_cast<FormType>(0x3c)) cell = reinterpret_cast<TESObjectCELL*>(parameter);
    if (!other || static_cast<unsigned char>(static_cast<unsigned char>(other->formType) - 0x3d) > 9) other = reference;
    TESObjectREFR* selected = static_cast<TESObjectREFR*>(other);
    double value = 0.0;
    if (selected && cell && selected->parentCell == cell) { value = 1.0; *result = value; }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, cellLogFormat, value);
    return true;
}
