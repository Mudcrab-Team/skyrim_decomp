// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x14e69c0 BSFadeNode::SetFadeRange
// Adapted bodies: none
#include "BSFadeNode_14e69c0.h"

void BSFadeNode::SetFadeRange(float a_near, float a_far)
{
    const float lowest = static_cast<float>(minFadeNear);
    if (!(a_near >= lowest)) {
        fadeNear = lowest;
        const float doubled = lowest + lowest;
        fadeFar = doubled > a_far ? doubled : a_far;
    } else {
        fadeNear = a_near;
        fadeFar = a_far;
    }
}
