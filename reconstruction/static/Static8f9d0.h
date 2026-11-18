// Source exposure: binary-analysis
// Static8f9d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f9d0;
extern void construct(Static8f9d0*, const Descriptor*);
extern void destroy(Static8f9d0*);
struct Static8f9d0 {
    void* value;
    Static8f9d0() { construct(this, &descriptor); }
    ~Static8f9d0() { destroy(this); }
};
