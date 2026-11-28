// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BSStreamParserData: CRASHLOGGER_PDB(59818@2026.10.24); listed name BSStreamParserData::ctor disagrees with destructor behavior
// BSStreamParserDataBase, BSStreamParserInner, inner: GUESS(low)
#pragma once

class BSStreamParserInner
{
public:
    virtual ~BSStreamParserInner();
};

class BSStreamParserDataBase
{
public:
    virtual ~BSStreamParserDataBase() {}
};

class BSStreamParserData : public BSStreamParserDataBase
{
public:
    ~BSStreamParserData() override;  // compared: 0x1572130

    BSStreamParserInner* inner;  // 08
};
