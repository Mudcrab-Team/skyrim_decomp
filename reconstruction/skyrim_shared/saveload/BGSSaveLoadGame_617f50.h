// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSSaveLoadGame: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function617f50: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Input617f50, Ref617f50, Cell617f50, Manager617f50, State617f50, manager617f50, state617f50: GUESS(low) STANDIN; save-load reference registration
struct Ref617f50;
struct Cell617f50 { void Remove(Ref617f50*); };
struct Ref617f50 { std::uint8_t unknown00[0x60]; Cell617f50* cell; bool First(); bool Second(); bool Third(); void Set(bool); };
struct Input617f50 { virtual ~Input617f50(); virtual void Unk01(); virtual void Unk02(); virtual void Unk03(); virtual void Unk04(); virtual void Unk05(); virtual void Unk06(); virtual void Unk07(); virtual void Unk08(); virtual void Unk09(); virtual void Unk0A(); virtual void Unk0B(); virtual void Unk0C(); virtual void Unk0D(); virtual void Unk0E(); virtual void Unk0F(); virtual void Unk10(); virtual void Unk11(); virtual void Unk12(); virtual void Unk13(); virtual void Unk14(); virtual void Unk15(); virtual void Unk16(); virtual void Unk17(); virtual void Unk18(); virtual void Unk19(); virtual void Unk1A(); virtual void Unk1B(); virtual void Unk1C(); virtual void Unk1D(); virtual void Unk1E(); virtual void Unk1F(); virtual void Unk20(); virtual void Unk21(); virtual void Unk22(); virtual void Unk23(); virtual void Unk24(); virtual void Unk25(); virtual void Unk26(); virtual void Unk27(); virtual void Unk28(); virtual void Unk29(); virtual void Unk2A(); virtual void Unk2B(); virtual Ref617f50* GetReference(); };
struct Manager617f50 { void Prepare(); };
struct State617f50 { void Register(Ref617f50*,bool); };
extern Manager617f50* manager617f50;
extern State617f50* state617f50;

class BGSSaveLoadGame
{
public:

    void Function617f50(Input617f50* input);
};
