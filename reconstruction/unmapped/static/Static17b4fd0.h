// Source exposure: binary-analysis
// Static17b4fd0, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b4fd0;
extern void construct(Static17b4fd0*);
struct Static17b4fd0 {
    Static17b4fd0() { construct(this); }
    ~Static17b4fd0() {}
};
