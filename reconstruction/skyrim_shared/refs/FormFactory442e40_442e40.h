// Source exposure: binary-analysis
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Hazard::SetExclusiveBranch: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); PDB name does not match this 8-byte factory deleting destructor
// FormFactoryBase442e40, FormFactory442e40, UnregisterFormFactory: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;
void UnregisterFormFactory(std::uint8_t a_formType);

class FormFactoryBase442e40
{
public:
    virtual ~FormFactoryBase442e40() {}
};
static_assert(sizeof(FormFactoryBase442e40) == 0x08, "FormFactoryBase442e40 size");

class FormFactory442e40 : public FormFactoryBase442e40
{
public:
    FormFactory442e40();
    ~FormFactory442e40() override;  // compared: 0x442e40
};
static_assert(sizeof(FormFactory442e40) == 0x08, "FormFactory442e40 size");
