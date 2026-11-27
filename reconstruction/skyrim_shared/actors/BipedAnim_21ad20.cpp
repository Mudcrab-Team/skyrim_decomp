// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BipedAnim: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function21ad20: GUESS(low); provisional member name
// 0x21ad20 BipedAnim::Function21ad20
// CI hash: 0x21ad20 ?Function21ad20@BipedAnim@@QEAAXPEAUForm21ad20@@@Z
#include "BipedAnim_21ad20.h"

// Guess: Apply the valid biped form and cache its value subobject.
void BipedAnim::Function21ad20(Form21ad20* form)
{
    if (form && form->type == 0x2a) {
        if (!disable21ad20) { Apply(&state, true, 0); }
        state.form = form;
        state.value = &form->value;
    }
}
