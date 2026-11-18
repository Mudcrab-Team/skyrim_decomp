// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x29e710 BGSKeyword::GetFormEditorID
#include "BGSKeyword.h"

const char* BGSKeyword::GetFormEditorID() const
{
    return formEditorID._data;
}
