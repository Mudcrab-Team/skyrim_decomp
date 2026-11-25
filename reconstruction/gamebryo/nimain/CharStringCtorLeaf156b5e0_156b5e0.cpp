// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0x156b5e0 CharStringCtorLeaf156b5e0::CharStringCtorLeaf156b5e0
#include "CharStringCtorLeaf156b5e0_156b5e0.h"

CharStringCtorLeaf156b5e0::CharStringCtorLeaf156b5e0(char value)
{
    auto* storage = static_cast<std::size_t*>(AllocateCharStringStorage156b5e0(32));
    storage[0] = 32;
    storage[1] = 1;
    storage[2] = 0;
    char* text = reinterpret_cast<char*>(storage + 3);
    data = text;
    text[0] = value;
    text[1] = '\0';
    if (data) {
        std::size_t length = static_cast<std::size_t>(-1);
        do {
            ++length;
        } while (data[length] != '\0');
        reinterpret_cast<std::size_t*>(data)[-1] = length;
    }
}
