// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// PathingRequestFly, GetType, BSCRC32, GenerateCRC, PathingRequestFlyCRC: GUESS(low)
#pragma once
extern unsigned int PathingRequestFlyCRC;
class BSCRC32 { public: static void GenerateCRC(unsigned int&, const char*, unsigned int); };
class PathingRequestFly { public: unsigned int GetType() const; };
