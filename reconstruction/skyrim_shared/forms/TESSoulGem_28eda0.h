// Source exposure: mixed; binary-analysis and permitted declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: adapted destructor from fo4-private@1b765c70; inferred layout
// Adapted bodies: TESSoulGem::~TESSoulGem
// TESSoulGem::~TESSoulGem: SIBLING(fo4-private@1b765c70, author-permission)
// TESSoulGem: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// ~TESSoulGem: GUESS(low); provisional member name
// TESSoulGem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESSoulGem.cpp:43
#pragma once
#include <cstdint>
#include <cstddef>

// Layout components: STANDIN GUESS(low); observed multiple-base extents
class Bound28eda0 { public: virtual ~Bound28eda0() {} std::uint8_t unknown08[40]; };
class Name28eda0 { public: virtual ~Name28eda0() {} std::uint8_t unknown08[8]; };
class Model28eda0 { public: virtual ~Model28eda0() {} std::uint8_t unknown08[48]; };
class Icon28eda0 { public: virtual ~Icon28eda0() {} std::uint8_t unknown08[8]; };
class Value28eda0 { public: virtual ~Value28eda0() {} std::uint8_t unknown08[8]; };
class Weight28eda0 { public: virtual ~Weight28eda0() {} std::uint8_t unknown08[8]; };
class Destruction28eda0 { public: virtual ~Destruction28eda0() {} std::uint8_t unknown08[8]; };
class Message28eda0 { public: virtual ~Message28eda0() {} std::uint8_t unknown08[16]; };
class Sounds28eda0 { public: virtual ~Sounds28eda0() {} std::uint8_t unknown08[16]; };
class Keywords28eda0 { public: virtual ~Keywords28eda0() {} std::uint8_t unknown08[16]; };
class Misc28eda0 : public Bound28eda0, public Name28eda0, public Model28eda0, public Icon28eda0, public Value28eda0, public Weight28eda0, public Destruction28eda0, public Message28eda0, public Sounds28eda0, public Keywords28eda0 { public: virtual ~Misc28eda0(); };

class TESSoulGem : public Misc28eda0
{
public:
    std::uint8_t unknown100[0x10];
    virtual ~TESSoulGem();
    void ClearData();


};
