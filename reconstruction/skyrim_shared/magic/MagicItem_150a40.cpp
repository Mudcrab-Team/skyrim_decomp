// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// MagicItem: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function150a40: GUESS(low); provisional member name
// 0x150a40 MagicItem::Function150a40
// CI hash: 0x150a40 ?Function150a40@MagicItem@@SAPEAV1@I@Z
#include "MagicItem_150a40.h"

// Guess: Resolve a magic form identity and perform the runtime cast.
MagicItem* MagicItem::Function150a40(unsigned id)
{
    auto* form=ResolveMagicForm(id);
    if(!form || !form->IsMagic()) { return nullptr; }
    return static_cast<MagicItem*>(CastMagicForm(form,0,&formType150a40,&magicType150a40,0));
}
