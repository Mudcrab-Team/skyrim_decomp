// TESModel, sub, Update, FixedString: GUESS(low)
// model, textures, addons, numTextures, numAddons: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body and public prefix declarations adapted from CommonLibSSE-NG, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
// TESModel, sub, Update, FixedString: GUESS(low)
// model, textures, addons, numTextures, numAddons: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
namespace BSResource { struct ID; }
struct FixedString { const char* data; };
class TESModel {
public:
    virtual ~TESModel();
    static void sub(TESModel*, void*);
    FixedString model;
    BSResource::ID* textures;
    std::uint32_t* addons;
    std::uint16_t numTextures;
    std::uint16_t numAddons;
};
void Update(BSResource::ID**, std::uint16_t*, std::uint32_t**, std::uint16_t*, void*);
