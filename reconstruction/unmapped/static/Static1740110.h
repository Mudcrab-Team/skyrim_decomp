// Source exposure: binary-analysis
// Static1740110, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static1740110;
extern void construct(Static1740110*);
struct Static1740110 {
    Static1740110() { construct(this); }
    ~Static1740110() {}
};
