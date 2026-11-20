// Source exposure: binary-analysis
// Static17b0d60, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b0d60;
extern void construct(Static17b0d60*);
struct Static17b0d60 {
    Static17b0d60() { construct(this); }
    ~Static17b0d60() {}
};
