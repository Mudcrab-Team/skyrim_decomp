// Source exposure: binary-analysis
// Static17b2620, Invoke, object, construct: GUESS(low) STANDIN
// Origin: primitive-empty-entry v1
#pragma once
struct Static17b2620;
extern void construct(Static17b2620*);
struct Static17b2620 {
    Static17b2620() { construct(this); }
    ~Static17b2620() {}
};
