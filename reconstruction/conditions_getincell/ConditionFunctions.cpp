// Build: sse-steam-1-7-104; RVA 0x3334e0; 143 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESForm fields and TESObjectREFR members: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from public headers.
// names: GUESS(low); names and signatures are tentative.
// MIT License
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// ConditionFunctions, ConditionFunctions::GetInCell: GUESS(low); the static source container and original signature are unverified.
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
