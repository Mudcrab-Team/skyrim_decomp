// Source exposure: binary-analysis
// Static17b1a30, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b1a30;
extern void construct(Static17b1a30*);
struct Static17b1a30 {
    Static17b1a30() { construct(this); }
    ~Static17b1a30() {}
};
