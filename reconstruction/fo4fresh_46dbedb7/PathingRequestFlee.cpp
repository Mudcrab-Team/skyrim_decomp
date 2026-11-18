// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlee.cpp:56
// PathingRequestFlee, PathingRequestFlee::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestFlee_typeCRC, PathingRequestFlee_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// 0x4f4f70 PathingRequestFlee::GetType
#include "PathingRequestFlee.h"

extern unsigned int PathingRequestFlee_typeCRC;
extern const char PathingRequestFlee_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestFlee::GetType() const { if (!PathingRequestFlee_typeCRC) GenerateTypeCRC(PathingRequestFlee_typeCRC, PathingRequestFlee_typeName, 0); return PathingRequestFlee_typeCRC; }
