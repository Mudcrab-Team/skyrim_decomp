// Source exposure: binary-analysis
// Static8b5d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b5d0;
extern void construct(Static8b5d0*, const Descriptor*);
extern void destroy(Static8b5d0*);
struct Static8b5d0 {
    void* value;
    Static8b5d0() { construct(this, &descriptor); }
    ~Static8b5d0() { destroy(this); }
};
