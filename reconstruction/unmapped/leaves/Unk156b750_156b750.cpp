// CI hash: 0x156b750 ?Function156b750@Unk156b750@@QEAAIXZ
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk156b750: STANDIN GUESS(low)
// Unk156b750::Function156b750: GUESS(low)
// Unk156b750::data, AllocationPrefix156b750: GUESS(low)
// 0x156b750 Unk156b750::Function156b750
#include "Unk156b750_156b750.h"

// Read the count from the allocation prefix before the variable-sized payload.
std::uint32_t Unk156b750::Function156b750()
{
    if (!data)
        return 0;
    const AllocationPrefix156b750* header = reinterpret_cast<const AllocationPrefix156b750*>(data) - 1;
    return header->count;
}
