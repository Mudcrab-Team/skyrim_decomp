// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMoviePlayer; size 0xc0
#pragma once

#include "BSTEventSink_RE__InputEvent_e78270ba.h"
#include "BSTEventSource_RE__BSMusicEvent_c03f2bac.h"
#include "MoviePlayer.h"
struct BGSMoviePlayer {
    MoviePlayer _base;
    BSTEventSink_RE__InputEvent_e78270ba _base_BSTEventSink_RE_InputEvent__;
    BSTEventSource_RE__BSMusicEvent_c03f2bac _base_BSTEventSource_RE_BSMusicEvent_;
    unsigned char unkB8;
    unsigned char padB9;
    unsigned short padBA;
    unsigned int padBC;
};
static_assert(sizeof(BGSMoviePlayer) == 192, "BGSMoviePlayer layout differs from the PDB");
