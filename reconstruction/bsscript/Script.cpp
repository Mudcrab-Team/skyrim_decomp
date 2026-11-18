// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x344760 Script::InitItemImpl
// 0x3463a0 Script::GetProcessScripts
#include "Script.h"

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
