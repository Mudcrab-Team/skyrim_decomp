// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyTakeOff.cpp:53 (PathingRequestFlyTakeOff::GetType)
// PathingRequestFlyTakeOff, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
#pragma once
class BSCRC32 { public: static void GenerateCRC(unsigned int& value, const char* name, int mode); };
class PathingRequestFlyTakeOff { public: static unsigned int typeId; unsigned int GetType() const; };
