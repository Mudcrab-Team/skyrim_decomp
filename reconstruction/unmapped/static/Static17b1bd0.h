// Source exposure: binary-analysis
// Static17b1bd0, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b1bd0;
extern void construct(Static17b1bd0*);
struct Static17b1bd0 {
    Static17b1bd0() { construct(this); }
    ~Static17b1bd0() {}
};
