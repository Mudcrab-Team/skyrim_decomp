// Source exposure: binary-analysis
// Static8bce0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8bce0;
extern void construct(Static8bce0*, const Descriptor*);
extern void destroy(Static8bce0*);
struct Static8bce0 {
    void* value;
    Static8bce0() { construct(this, &descriptor); }
    ~Static8bce0() { destroy(this); }
};
