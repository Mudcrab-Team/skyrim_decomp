// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Form and TESGlobal fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/T/TESForm.h and include/RE/T/TESGlobal.h.
// names: GUESS(low); names and signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ConditionFunctions, ConditionFunctions::GetGlobalValue: GUESS(low); the static source container and original signature are unverified.
// 0x3342c0 Condition::GetGlobalValue
#include "ConditionFunctions_3342c0.h"
class TESObjectREFR;
struct Form {
    void* virtualTable;
    void* sourceFiles;
    unsigned int formFlags, formID;
    unsigned short inGameFlags;
    unsigned char formType, pad1b;
    unsigned int pad1c;
};
struct BSString { char* data; unsigned short size, capacity; };
struct TESGlobal : Form { BSString editorID; unsigned char type, pad31; unsigned short pad32; float value; };
extern void* conditionLogger;
extern const char globalLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetGlobalValue(TESObjectREFR*, Form* parameter, void*, double* result)
{
    *result = -1.0;
    TESGlobal* global = nullptr;
    if (parameter && parameter->formType == 9) global = static_cast<TESGlobal*>(parameter);
    double value = -1.0;
    if (global) { value = global->value; *result = value; }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, globalLogFormat, value);
    return true;
}
