// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WaterShaderData; size 0xe8
#pragma once

#include "Color_aa361e09.h"
#include "DepthProperties.h"
struct WaterShaderData {
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float sunSpecularPower;
    float reflectionAmount;
    float fresnelAmount;
    unsigned int unk1C;
    float aboveWaterFogDistNear;
    float aboveWaterFogDistFar;
    Color_aa361e09 shallowWaterColor;
    Color_aa361e09 deepWaterColor;
    Color_aa361e09 reflectionWaterColor;
    unsigned int unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float displacementSize;
    float displacementForce;
    float displacementVelocity;
    float displacementFalloff;
    float displacementDampener;
    float unk5C;
    float noiseFalloff;
    float noiseWindDirectionA[3];
    float noiseWindSpeedA[3];
    float unk7C;
    float unk80;
    float aboveWaterFogAmount;
    float unk88;
    float underwaterFogAmount;
    float underwaterFogDistNear;
    float underwaterFogDistFar;
    float refractionMagnitude;
    float specularPower;
    float unkA0;
    float specularRadius;
    float specularBrightness;
    float uvScaleA[3];
    float amplitudeA[3];
    float reflectionMagnitude;
    float sunSparkleMagnitude;
    float sunSpecularMagnitude;
    DepthProperties depthProperties;
    float sunSparklePower;
    float flowmapScale;
};
static_assert(sizeof(WaterShaderData) == 232, "WaterShaderData layout differs from the PDB");
