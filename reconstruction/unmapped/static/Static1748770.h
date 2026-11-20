// Source exposure: binary-analysis
// Static1748770, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static1748770;
extern void construct(Static1748770*);
struct Static1748770 {
    Static1748770() { construct(this); }
    ~Static1748770() {}
};
