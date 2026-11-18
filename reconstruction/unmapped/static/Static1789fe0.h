// Source exposure: binary-analysis
// Static1789fe0, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static1789fe0;
extern void construct(Static1789fe0*);
struct Static1789fe0 {
    Static1789fe0() { construct(this); }
    ~Static1789fe0() {}
};
