// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// SaveStorageWrapper::GetPosition: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSSaveLoadStorageWrappers.cpp:50
// SaveStorageWrapper, SaveStorageWrapper::GetPosition: GUESS(low)
// SaveStorageWrapper fields: STANDIN GUESS(low)
// 0x63a4d0 SaveStorageWrapper::GetPosition
#include "SaveStorageWrapper_63a4d0.h"
std::uint32_t SaveStorageWrapper::GetPosition() const { if (useBuffer && buffer) return buffer->head - buffer->start; return (file->position != 0xffffffff ? file->position : file->fallback) - start; }
