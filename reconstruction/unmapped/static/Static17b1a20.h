// Source exposure: binary-analysis
// Static17b1a20, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b1a20;
extern void construct(Static17b1a20*);
struct Static17b1a20 {
    Static17b1a20() { construct(this); }
    ~Static17b1a20() {}
};
