// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTArray container helpers.
// BSTArrayFindEraseOrdered, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x1c5810 BSTArrayFindEraseOrdered::Op1c5810
// 0x1c58c0 BSTArrayFindEraseOrdered::Op1c58c0
// 0x1c5970 BSTArrayFindEraseOrdered::Op1c5970
// 0x1c5a20 BSTArrayFindEraseOrdered::Op1c5a20
// 0x2dc170 BSTArrayFindEraseOrdered::Op2dc170
// 0x2dc220 BSTArrayFindEraseOrdered::Op2dc220
// 0x397c50 BSTArrayFindEraseOrdered::Op397c50
// 0x397d00 BSTArrayFindEraseOrdered::Op397d00
// 0x62af00 BSTArrayFindEraseOrdered::Op62af00
// 0x62afb0 BSTArrayFindEraseOrdered::Op62afb0
// 0x766020 BSTArrayFindEraseOrdered::Op766020
// 0x7660d0 BSTArrayFindEraseOrdered::Op7660d0
// 0x94c790 BSTArrayFindEraseOrdered::Op94c790
// 0x94c840 BSTArrayFindEraseOrdered::Op94c840
// 0x1569860 BSTArrayFindEraseOrdered::Op1569860
// 0x1569910 BSTArrayFindEraseOrdered::Op1569910
#include "BSTArrayFindEraseOrdered.h"

bool BSTArrayFindEraseOrdered::Op1c5810(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op1c58c0(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op1c5970(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op1c5a20(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op2dc170(BSTArrayHeap* self, const std::uint32_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint32_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 4u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op2dc220(BSTArrayHeap* self, const std::uint32_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint32_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 4u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op397c50(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op397d00(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op62af00(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op62afb0(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op766020(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op7660d0(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op94c790(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op94c840(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op1569860(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

bool BSTArrayFindEraseOrdered::Op1569910(BSTArrayHeap* self, const std::uint64_t* key)
{
    std::uint32_t size = self->size;
    std::uint32_t found = 0xFFFFFFFFu;
    for (std::uint32_t i = 0u; i < size && found == 0xFFFFFFFFu; ++i) {
        if (static_cast<const std::uint64_t*>(self->data)[i] == *key) {
            found = i;
        }
    }
    if (found != 0xFFFFFFFFu) {
        void* data = self->data;
        if (size == 1u) {
            if (data) {
                self->size = 0u;
            }
        } else {
            ArrayMove_ce0980(&self->size, data, found, found + 1u, size - found - 1u, 8u);
            --self->size;
        }
    }
    return found != 0xFFFFFFFFu;
}

