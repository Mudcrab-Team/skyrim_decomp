// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// PathingRequestFlyLand, GetType, BSCRC32, GenerateCRC, PathingRequestFlyLandCRC: GUESS(low)
#pragma once
extern unsigned int PathingRequestFlyLandCRC;
class BSCRC32 { public: static void GenerateCRC(unsigned int&, const char*, unsigned int); };
class PathingRequestFlyLand { public: unsigned int GetType() const; };
