// Code origin: original; the listing and community declarations only
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// Function15757c0, CRC32SizeOfSize: GUESS(low); bodies are written from the local listing, no community code adapted
// 0x15757c0 BSShaderMaterial::Function15757c0
// 0x1575700 BSShaderMaterial::CopyMembers
// 0x15758f0 BSShaderMaterial::~BSShaderMaterial
#include "BSShaderMaterial.h"

void CRC32SizeOfSize(std::uint32_t* a_out, const void* a_data, std::uint32_t a_size);  // 0xce2510

// MaterialCrcRecord: GUESS(low); the 0x18-byte record hashed by Function15757c0
struct MaterialCrcRecord
{
    BSShaderPair  offset;  // 00
    BSShaderPair  scale;   // 08
    std::uint32_t seed;    // 10
    std::uint32_t pad;     // 14
};
static_assert(sizeof(MaterialCrcRecord) == 0x18, "MaterialCrcRecord size");

// Not compared on its own: the compiler emits the vftable here, and with it the deleting
// destructor that is compared.
BSShaderMaterial::BSShaderMaterial()
{
}

BSShaderMaterial::Feature BSShaderMaterial::GetFeature() const
{
    return Feature::kDefault;
}

BSShaderMaterial::Type BSShaderMaterial::GetType() const
{
    return static_cast<Type>(0);
}

BSShaderMaterial* BSShaderMaterial::GetDefault()
{
    return gDefaultShaderMaterial;
}

void BSShaderMaterial::CopyMembers(BSShaderMaterial* a_other)
{
    RawAt<BSShaderPair>(this, 0x0c) = RawAt<BSShaderPair>(a_other, 0x0c);
    RawAt<BSShaderPair>(this, 0x14) = RawAt<BSShaderPair>(a_other, 0x14);
    RawAt<BSShaderPair>(this, 0x1c) = RawAt<BSShaderPair>(a_other, 0x1c);
    RawAt<BSShaderPair>(this, 0x24) = RawAt<BSShaderPair>(a_other, 0x24);
}

std::uint32_t BSShaderMaterial::Function15757c0(std::uint32_t a_seed)
{
    MaterialCrcRecord record;
    record.offset = RawAt<BSShaderPair>(this, 0x0c);
    record.scale = RawAt<BSShaderPair>(this, 0x1c);
    record.seed = a_seed;
    record.pad = 0;
    std::uint32_t crc;
    CRC32SizeOfSize(&crc, &record, sizeof(record));
    return crc;
}
