// Source exposure: binary-analysis
// Static178a1e0, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static178a1e0;
extern void construct(Static178a1e0*);
struct Static178a1e0 {
    Static178a1e0() { construct(this); }
    ~Static178a1e0() {}
};
