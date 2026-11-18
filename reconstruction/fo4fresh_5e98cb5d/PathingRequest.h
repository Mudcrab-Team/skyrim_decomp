// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// PathingRequest, GetType, BSCRC32, GenerateCRC, PathingRequestCRC: GUESS(low)
#pragma once
extern unsigned int PathingRequestCRC;
class BSCRC32 { public: static void GenerateCRC(unsigned int&, const char*, unsigned int); };
class PathingRequest { public: unsigned int GetType() const; };
