// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyAction.cpp:58
// PathingRequestFlyAction, PathingRequestFlyAction::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestFlyAction_typeCRC, PathingRequestFlyAction_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// 0x4f5ac0 PathingRequestFlyAction::GetType
#include "PathingRequestFlyAction.h"

extern unsigned int PathingRequestFlyAction_typeCRC;
extern const char PathingRequestFlyAction_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestFlyAction::GetType() const { if (!PathingRequestFlyAction_typeCRC) GenerateTypeCRC(PathingRequestFlyAction_typeCRC, PathingRequestFlyAction_typeName, 0); return PathingRequestFlyAction_typeCRC; }
