// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Base29e620, Obj29e620: GUESS(low)
#pragma once

class Base29e620
{
public:
    virtual ~Base29e620();
};

class Obj29e620 : public Base29e620
{
public:
    ~Obj29e620() override;

    void Cleanup();
};
