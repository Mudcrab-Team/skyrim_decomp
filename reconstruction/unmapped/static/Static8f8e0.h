// Source exposure: binary-analysis
// Static8f8e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f8e0;
extern void construct(Static8f8e0*, const Descriptor*);
extern void destroy(Static8f8e0*);
struct Static8f8e0 {
    void* value;
    Static8f8e0() { construct(this, &descriptor); }
    ~Static8f8e0() { destroy(this); }
};
