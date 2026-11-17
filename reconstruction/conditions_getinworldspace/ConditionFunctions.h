// Build: sse-steam-1-7-104; RVA 0x333580; 192 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESForm::formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetInWorldspace: GUESS(low); the static source container and original signature are unverified.
#pragma once
class TESForm;

class ConditionFunctions
{
public:
    static bool GetInWorldspace(TESForm* reference, TESForm* parameter, TESForm* other, double* result);
};
