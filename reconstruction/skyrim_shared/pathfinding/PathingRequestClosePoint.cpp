// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestClosePoint.cpp:77
// PathingRequestClosePoint, PathingRequestClosePoint::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestClosePoint_typeCRC, PathingRequestClosePoint_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// 0x4f23e0 PathingRequestClosePoint::GetType
#include "PathingRequestClosePoint.h"

extern unsigned int PathingRequestClosePoint_typeCRC;
extern const char PathingRequestClosePoint_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestClosePoint::GetType() const { if (!PathingRequestClosePoint_typeCRC) GenerateTypeCRC(PathingRequestClosePoint_typeCRC, PathingRequestClosePoint_typeName, 0); return PathingRequestClosePoint_typeCRC; }
