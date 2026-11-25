// Source exposure: binary-analysis
// Unlock1223f50: GUESS(low) STANDIN; original owner is unknown
#pragma once
#include <cstdint>
class Primary1223f50 { public: virtual ~Primary1223f50(); std::uint64_t unk08, unk10; };
class SecondaryBase1223f50 { public: virtual ~SecondaryBase1223f50(); };
class Secondary1223f50 : public SecondaryBase1223f50 { public: virtual ~Secondary1223f50() {} };

class Unlock1223f50 : public Primary1223f50, public Secondary1223f50 { public: virtual ~Unlock1223f50(); };
