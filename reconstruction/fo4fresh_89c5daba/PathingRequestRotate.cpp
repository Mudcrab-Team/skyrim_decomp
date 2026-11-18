// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestRotate.cpp:26
// PathingRequestRotate, PathingRequestRotate::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestRotate_typeCRC, PathingRequestRotate_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// 0x4f9080 PathingRequestRotate::GetType
#include "PathingRequestRotate.h"

extern unsigned int PathingRequestRotate_typeCRC;
extern const char PathingRequestRotate_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestRotate::GetType() const { if (!PathingRequestRotate_typeCRC) GenerateTypeCRC(PathingRequestRotate_typeCRC, PathingRequestRotate_typeName, 0); return PathingRequestRotate_typeCRC; }
