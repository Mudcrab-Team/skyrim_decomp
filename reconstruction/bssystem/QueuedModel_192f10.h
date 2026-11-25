// Source exposure: mixed (community headers; compared functions from the pinned image; a permitted sibling).
// Code origin: declarations and body adapted from a permitted sibling, bit positions and statics checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// QueuedModel::GenerateKey: SIBLING(fo4-private@1b765c70, author-permission)
// IOTask::iStaticCounter, IOTask::iStaticOffset, IOTask::iKey: GUESS(medium); spelled as in the permitted sibling body, which does not declare them in a permitted file
// QueuedModel, IOTask: STANDIN GUESS(low); only the members the compared function touches, header-gap IOTask
// IOTask::unknown08: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/ModelLoader.cpp:32
#pragma once

#include <cstdint>

class IOTask
{
public:
    virtual ~IOTask();

    static volatile long iStaticCounter;  // volatile: bumped by locked increments from several loader threads
    static volatile long iStaticOffset;   // volatile: bumped by locked increments from several loader threads

    std::uint8_t unknown08[0x08];  // 08
    std::int64_t iKey;             // 10
};

class QueuedModel : public IOTask
{
public:
    void GenerateKey();
};
