// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPath, IsUniqueAbsolute: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names and pattern: GUESS(low); operations observed on the target.
#pragma once
extern const char gPathPatternEeacf80[];
struct PathUniqueLeafeacf80
{
    static bool IsUniqueAbsolute(const char* path);
    static bool HasSpecialForm(const char* path);
    static const char* Normalize(const char* path);
};
