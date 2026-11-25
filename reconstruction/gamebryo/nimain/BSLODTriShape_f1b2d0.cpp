// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSLODTriShape: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionf1b2d0: GUESS(low); provisional member name
// 0xf1b2d0 BSLODTriShape::Functionf1b2d0
// CI hash: 0xf1b2d0 ?Functionf1b2d0@BSLODTriShape@@QEAAXPEAV1@PEAX@Z
#include "BSLODTriShape_f1b2d0.h"

// Guess: Copy the base shape and its level-of-detail values.
void BSLODTriShape::Functionf1b2d0(BSLODTriShape* output, void* context)
{
    CopyBase(output, context);
    output->first = first;
    output->second = second;
    output->third = third;
    output->flag = flag;
}
