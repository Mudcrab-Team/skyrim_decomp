// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// Adapted bodies: none
// 0x344430 Script::sub_1402E7B90
#include "Script_344430.h"

#include <cstring>

// Looks up a script variable by name, writing its ID and returning 's' or 'f' (or 0 if missing).
char Script::sub_1402E7B90(const char* a_name, std::uint32_t* a_outId)
{
    ScriptVariableNode* node = &variables;
    while (node)
    {
        ScriptVariable* var = node->item;
        if (!var)
        {
            break;
        }
        node = node->next;
        const char* varName = var->name ? var->name : "";
        if (_stricmp(varName, a_name) == 0)
        {
            *a_outId = var->id;
            return var->isInteger ? 's' : 'f';
        }
    }
    *a_outId = 0;
    return 0;
}
