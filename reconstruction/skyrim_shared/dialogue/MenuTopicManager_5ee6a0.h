// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// MenuTopicManager, MenuTopicManager::SelectNextResponse, MenuTopicManager::selectedResponseNode: CRASHLOGGER_PDB(59818@2026.10.24)
// DialogueNode: GUESS
#pragma once

#include <cstdint>

struct DialogueNode
{
    void* item;
    DialogueNode* next;
};

class MenuTopicManager
{
  public:
    bool SelectNextResponse();

    std::uint8_t unk00[0x18];
    DialogueNode* selectedResponseNode;
};
