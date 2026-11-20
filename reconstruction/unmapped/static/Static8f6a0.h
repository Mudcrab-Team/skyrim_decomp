// Source exposure: binary-analysis
// Static8f6a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f6a0;
extern void construct(Static8f6a0*, const Descriptor*);
extern void destroy(Static8f6a0*);
struct Static8f6a0 {
    void* value;
    Static8f6a0() { construct(this, &descriptor); }
    ~Static8f6a0() { destroy(this); }
};
