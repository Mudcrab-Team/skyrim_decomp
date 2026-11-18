// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyOrbit.cpp:67
// PathingRequestFlyOrbit, PathingRequestFlyOrbit::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestFlyOrbit_typeCRC, PathingRequestFlyOrbit_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// 0x4f74f0 PathingRequestFlyOrbit::GetType
#include "PathingRequestFlyOrbit.h"

extern unsigned int PathingRequestFlyOrbit_typeCRC;
extern const char PathingRequestFlyOrbit_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestFlyOrbit::GetType() const { if (!PathingRequestFlyOrbit_typeCRC) GenerateTypeCRC(PathingRequestFlyOrbit_typeCRC, PathingRequestFlyOrbit_typeName, 0); return PathingRequestFlyOrbit_typeCRC; }
