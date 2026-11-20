// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and community declarations.
// names: GUESS(low); target call identity and function name remain unverified.
// 0x93ddd0 Inventory3DManager::LoadInventoryItem
#include "Inventory3DManager.h"
void Inventory3DManager::LoadInventoryItem(InventoryEntryData* entry) { if (entry) LoadInventoryItem(entry->object, entry->extraLists ? entry->extraLists->item : nullptr); }
