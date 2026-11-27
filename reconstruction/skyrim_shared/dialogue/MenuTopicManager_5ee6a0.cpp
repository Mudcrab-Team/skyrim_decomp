// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// Adapted bodies: none
// 0x5ee6a0 MenuTopicManager::SelectNextResponse
#include "MenuTopicManager_5ee6a0.h"

// Advances selectedResponseNode to the next response node and returns whether an item exists.
bool MenuTopicManager::SelectNextResponse()
{
    if (selectedResponseNode)
    {
        selectedResponseNode = selectedResponseNode->next;
        if (selectedResponseNode && selectedResponseNode->item)
        {
            return true;
        }
    }
    return false;
}
