// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of GetData2 and GetIngredientSkillUseModifier. Stamped as a twin of matched 0x14fd00 (skyrim_shared/magic/IngredientItem): source copied, names replaced by placeholders.
// Recipe: reconstruction/recipes/o2-fpfast.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x159af30 Owner159af30::Function159af30
#include "Owner159af30.h"

// guess: same compiled code as matched 0x14fd00 apart from relocated fields; its role here is not established.
Owner159af30::Data* Owner159af30::Function159af30()
{
    return &data;
}
