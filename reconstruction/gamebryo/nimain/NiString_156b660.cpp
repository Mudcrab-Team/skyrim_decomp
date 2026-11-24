// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0x156b660 NiString::NiString
#include "NiString_156b660.h"
#include <cstddef>

extern char* CopyStringStorage(const char*);

NiString::NiString(const char* text)
{
    data = CopyStringStorage(text);
    if (data) {
        std::size_t length = static_cast<std::size_t>(-1);
        do {
            ++length;
        } while (data[length] != '\0');
        reinterpret_cast<std::size_t*>(data)[-1] = length;
    }
}
