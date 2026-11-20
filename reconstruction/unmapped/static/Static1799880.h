// Source exposure: binary-analysis
// Static1799880, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static1799880;
extern void construct(Static1799880*);
struct Static1799880 {
    Static1799880() { construct(this); }
    ~Static1799880() {}
};
