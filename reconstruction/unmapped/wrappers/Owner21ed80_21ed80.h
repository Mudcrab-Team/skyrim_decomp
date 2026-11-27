// Source exposure: binary-analysis
// Code origin: original reconstruction from the local image.
// Owner21ed80, CleanUp, Member08, Member38: GUESS(low)
#pragma once

struct Member08
{
    void CleanUp();
    char unknown00[0x30];
};

struct Member38
{
    void CleanUp();
};

class Owner21ed80
{
public:
    void CleanUp();

    char unknown00[8];
    Member08 member08;
    Member38 member38;
};
