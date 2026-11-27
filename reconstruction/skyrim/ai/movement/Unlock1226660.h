// Source exposure: binary-analysis
// Unlock1226660: GUESS(low) STANDIN; original owner is unknown
#pragma once
#include <cstdint>
class Primary1226660 { public: virtual ~Primary1226660(); std::uint64_t unk08, unk10; };
class SecondaryBase1226660 { public: virtual ~SecondaryBase1226660(); };
class Secondary1226660 : public SecondaryBase1226660 { public: virtual ~Secondary1226660() {} };

class Unlock1226660 : public Primary1226660, public Secondary1226660 { public: virtual ~Unlock1226660(); };
