// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0xcd8c80 BSXAudio2AudioListener::Unk_01
// 0xcd8da0 BSXAudio2AudioListener::Unk_06
#include "BSXAudio2AudioListener.h"

void BSXAudio2AudioListener::Unk_01()
{
    field58 = 0;
    field60 = 0;
}

void BSXAudio2AudioListener::Unk_06(const std::uint32_t* a_src)
{
    unk2C = a_src[0];
    unk30 = a_src[1];
    unk34 = a_src[2];
    field64 = a_src[0];
    field68 = a_src[2];
    field6C = a_src[1];
}
