// Origin: original partial declarations from target listing and sibling type/name hints.
// Source exposure: mixed (pinned target listing and sibling hints).
// SaveStorageWrapper, SaveStorageWrapper::GetPosition: GUESS(low)
// SaveStorageWrapper fields: STANDIN GUESS(low)
// Supporting types: STANDIN GUESS(low)
#pragma once
#include <cstdint>
struct Buffer { std::uint8_t pad[8]; std::uint32_t start; std::uint8_t gap[4]; std::uint32_t head; };
struct StorageFile { std::uint8_t pad[0x58]; std::uint32_t position; std::uint8_t gap[0x114]; std::uint32_t fallback; };
class SaveStorageWrapper {
public: std::uint32_t GetPosition() const;
private: std::uint8_t pad[0x10]; Buffer* buffer; bool useBuffer; std::uint8_t gap[7]; StorageFile* file; std::uint32_t start;
};
