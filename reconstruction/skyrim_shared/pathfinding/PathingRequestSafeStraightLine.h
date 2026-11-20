// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// PathingRequestSafeStraightLine, GetType, BSCRC32, GenerateCRC, PathingRequestSafeStraightLineCRC: GUESS(low)
#pragma once
extern unsigned int PathingRequestSafeStraightLineCRC;
class BSCRC32 { public: static void GenerateCRC(unsigned int&, const char*, unsigned int); };
class PathingRequestSafeStraightLine { public: unsigned int GetType() const; };
