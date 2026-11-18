// Source exposure: binary-analysis
// Static17b2470, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b2470;
extern void construct(Static17b2470*);
struct Static17b2470 {
    Static17b2470() { construct(this); }
    ~Static17b2470() {}
};
