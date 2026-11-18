// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// PathingRequestHide, GetType, BSCRC32, GenerateCRC, PathingRequestHideCRC: GUESS(low)
#pragma once
extern unsigned int PathingRequestHideCRC;
class BSCRC32 { public: static void GenerateCRC(unsigned int&, const char*, unsigned int); };
class PathingRequestHide { public: unsigned int GetType() const; };
