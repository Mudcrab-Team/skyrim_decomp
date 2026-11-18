// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestStopMoving.cpp:17 (PathingRequestStopMoving::GetType)
// PathingRequestStopMoving, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
#pragma once
class BSCRC32 { public: static void GenerateCRC(unsigned int& value, const char* name, int mode); };
class PathingRequestStopMoving { public: static unsigned int typeId; unsigned int GetType() const; };
