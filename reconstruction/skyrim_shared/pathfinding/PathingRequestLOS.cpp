// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestLOS.cpp:57
// PathingRequestLOS, PathingRequestLOS::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestLOS_typeCRC, PathingRequestLOS_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// 0x4f82b0 PathingRequestLOS::GetType
#include "PathingRequestLOS.h"

extern unsigned int PathingRequestLOS_typeCRC;
extern const char PathingRequestLOS_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestLOS::GetType() const { if (!PathingRequestLOS_typeCRC) GenerateTypeCRC(PathingRequestLOS_typeCRC, PathingRequestLOS_typeName, 0); return PathingRequestLOS_typeCRC; }
