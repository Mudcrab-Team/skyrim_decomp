// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x344760 Script::InitItemImpl
// 0x3463a0 Script::GetProcessScripts
// 0x346a60 Script::~Script
// 0x346390 Script::SetProcessScripts
#include "Script.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
Script::Script()
{
}

// g_scriptProcessScripts: GUESS(low); a mutable global the compared GetProcessScripts reads at 0x207e511
extern bool g_scriptProcessScripts;
// ScriptInitItemHelper: GUESS(low); the target tail-jumps to it with this passed twice, at 0x344770
void ScriptInitItemHelper(Script* a_self, Script* a_other);

void Script::InitItemImpl()
{
    ScriptInitItemHelper(this, this);
}

bool Script::GetProcessScripts()
{
    return g_scriptProcessScripts;
}

void Script::SetProcessScripts(bool a_set)
{
    g_scriptProcessScripts = a_set;
}
