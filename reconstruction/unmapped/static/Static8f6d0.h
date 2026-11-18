// Source exposure: binary-analysis
// Static8f6d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f6d0;
extern void construct(Static8f6d0*, const Descriptor*);
extern void destroy(Static8f6d0*);
struct Static8f6d0 {
    void* value;
    Static8f6d0() { construct(this, &descriptor); }
    ~Static8f6d0() { destroy(this); }
};
