// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiString: SIBLING(fo4-private@1b765c70, author-permission)
// data: GUESS(low); stand-in for the observed string handle
#pragma once

class NiString
{
public:
    explicit NiString(const char* text);
    char* data;
};
