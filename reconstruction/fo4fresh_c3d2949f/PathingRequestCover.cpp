// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestCover.cpp:30
// PathingRequestCover, PathingRequestCover::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestCover_typeCRC, PathingRequestCover_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// 0x4f4300 PathingRequestCover::GetType
#include "PathingRequestCover.h"

extern unsigned int PathingRequestCover_typeCRC;
extern const char PathingRequestCover_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestCover::GetType() const { if (!PathingRequestCover_typeCRC) GenerateTypeCRC(PathingRequestCover_typeCRC, PathingRequestCover_typeName, 0); return PathingRequestCover_typeCRC; }
