// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x31b530 BGSColorForm::InitializeData
#include "BGSColorForm.h"

void BGSColorForm::InitializeData()
{
    color.value = 0;
    flags = 0;
}

void BGSColorForm::ClearData()
{
    color.value = 0;
    flags = 0;
}
