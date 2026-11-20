// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFaceGenAnimationData; size 0x230
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFaceGenKeyframeMultiple_8b68f6fe.h"
#include "BSSpinLock.h"
#include "EyesBlinkingStage.h"
#include "NiExtraData.h"
struct DialogueData;
struct BSFaceGenAnimationData {
    NiExtraData _base;
    BSFaceGenKeyframeMultiple_8b68f6fe* transitionTargetKeyFrame;
    BSFaceGenKeyframeMultiple_8b68f6fe expressionKeyFrame;
    BSFaceGenKeyframeMultiple_8b68f6fe expressionKeyFrame2;
    BSFaceGenKeyframeMultiple_8b68f6fe modifierKeyFrame;
    BSFaceGenKeyframeMultiple_8b68f6fe phenomeKeyFrame;
    BSFaceGenKeyframeMultiple_8b68f6fe customKeyFrame;
    BSFaceGenKeyframeMultiple_8b68f6fe expression3;
    BSFaceGenKeyframeMultiple_8b68f6fe modifier1;
    BSFaceGenKeyframeMultiple_8b68f6fe modifier3;
    BSFaceGenKeyframeMultiple_8b68f6fe phoneme1;
    BSFaceGenKeyframeMultiple_8b68f6fe phoneme3;
    BSFaceGenKeyframeMultiple_8b68f6fe custom1;
    BSFaceGenKeyframeMultiple_8b68f6fe custom3;
    float unk1A0;
    float unk1A4;
    float unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int nk1B4;
    unsigned int unk1B8;
    float eyesHeading;
    float eyesPitch;
    unsigned int pad1C4;
    unsigned long long unk1C8;
    unsigned char unk1D0;
    unsigned char unk1D1;
    unsigned char nk1D2;
    unsigned char unk1D3;
    float eyesHeadingBase;
    float eyesPitchBase;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    EyesBlinkingStage eyesBlinkingStage;
    float eyesBlinkingTimer;
    float eyesOffsetTimer;
    float eyesHeadingOffset;
    float eyesPitchOffset;
    unsigned char unk214;
    unsigned char unk215;
    unsigned char unk216;
    bool unk217;
    unsigned char unk218;
    unsigned char unk219;
    unsigned char unk21A;
    unsigned char unk21B;
    unsigned char unk21C;
    unsigned char unk21D;
    bool exprOverride;
    unsigned char unk21F;
    BSSpinLock lock;
    DialogueData* dialogueData;
};
static_assert(sizeof(BSFaceGenAnimationData) == 560, "BSFaceGenAnimationData layout differs from the PDB");
