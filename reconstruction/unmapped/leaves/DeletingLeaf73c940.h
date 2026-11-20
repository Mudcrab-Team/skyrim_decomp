// Source exposure: binary-analysis
// DeletingLeaf73c940, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf73c940 {
public:
    virtual ~DeletingLeaf73c940() {}
};
static_assert(sizeof(DeletingLeaf73c940) == 8, "minimal virtual interface size");
