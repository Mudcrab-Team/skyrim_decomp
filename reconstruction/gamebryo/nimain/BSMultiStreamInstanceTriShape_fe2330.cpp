// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSMultiStreamInstanceTriShape: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionfe2330: GUESS(low); provisional member name
// 0xfe2330 BSMultiStreamInstanceTriShape::Functionfe2330
// CI hash: 0xfe2330 ?Functionfe2330@BSMultiStreamInstanceTriShape@@QEAAXPEAV1@PEAX@Z
#include "BSMultiStreamInstanceTriShape_fe2330.h"

// Guess: Copy the base shape and the three instance values.
void BSMultiStreamInstanceTriShape::Functionfe2330(BSMultiStreamInstanceTriShape* output, void* context)
{
    CopyBase(output, context);
    output->first = first;
    output->second = second;
    output->third = third;
}
