// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSProceduralLightningController, BSProceduralLightningController::Functionffdf10: GUESS(low)
// Payload, unk180: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Payload
{
public:
    virtual ~Payload();
};

class BSProceduralLightningController
{
public:
    void Functionffdf10(Payload* a_new);

    unsigned char pad000[0x180];
    Payload* unk180;
};
