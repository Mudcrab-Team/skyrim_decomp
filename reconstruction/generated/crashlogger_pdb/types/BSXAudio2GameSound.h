// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSXAudio2GameSound; size 0x220
#pragma once

#include "BSGameSound.h"
#include "IXAudio2VoiceCallback.h"
#include "X3DAUDIO_CONE.h"
#include "X3DAUDIO_DISTANCE_CURVE.h"
#include "X3DAUDIO_DSP_SETTINGS.h"
#include "X3DAUDIO_EMITTER.h"
struct BSXAudio2DataSrc;
struct IXAudio2SourceVoice;
struct StreamPacket;
struct BSXAudio2GameSound {
    BSGameSound _base;
    IXAudio2VoiceCallback _base_IXAudio2VoiceCallback;
    BSXAudio2DataSrc* src;
    unsigned int buffersSubmitted;
    unsigned short buffersQueued;
    unsigned short packetIndex;
    X3DAUDIO_DISTANCE_CURVE volumeCurve;
    unsigned char curvePoints_raw[48];
    unsigned int lastUpdateTime;
    unsigned int samplesPlayed;
    unsigned int playbackPosition;
    IXAudio2SourceVoice* sourceVoice;
    X3DAUDIO_DSP_SETTINGS dspSettings;
    X3DAUDIO_EMITTER emitter;
    X3DAUDIO_CONE cone;
    unsigned int dataOffset;
    unsigned char pad20C[4];
    StreamPacket* streamPackets[2];
};
static_assert(sizeof(BSXAudio2GameSound) == 544, "BSXAudio2GameSound layout differs from the PDB");
