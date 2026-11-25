// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BGSPackageDataRefOLD","rationale":"vtable owner and slot; method spelling invented","slot":6},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x44dc60 (skyrim/ai/BGSPackageDataRefOLD): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// 0x7bf310 Owner7bf310::Function7bf310
#include "Owner7bf310.h"

// guess: same compiled code as matched 0x44dc60 apart from relocated fields; its role here is not established.
std::uint32_t* Owner7bf310::Function7bf310(std::uint32_t* a_out) const
{
    *a_out = value;
    return a_out;
}
