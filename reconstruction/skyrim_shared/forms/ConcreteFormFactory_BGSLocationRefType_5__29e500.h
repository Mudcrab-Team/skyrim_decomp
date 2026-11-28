// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// ConcreteFormFactory_BGSLocationRefType_5_, ConcreteFormFactory_BGSLocationRefType_5_::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// IFormFactory29e500, UnregisterFormFactory: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;
void UnregisterFormFactory(std::uint8_t a_formType);

class IFormFactory29e500
{
public:
    virtual ~IFormFactory29e500() {}
};

class ConcreteFormFactory_BGSLocationRefType_5_ : public IFormFactory29e500
{
public:
    ConcreteFormFactory_BGSLocationRefType_5_();
    virtual ~ConcreteFormFactory_BGSLocationRefType_5_() override;

    std::uint64_t unk08;  // 08
};
static_assert(sizeof(ConcreteFormFactory_BGSLocationRefType_5_) == 0x10, "ConcreteFormFactory_BGSLocationRefType_5_ size");
