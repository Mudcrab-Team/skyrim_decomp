// Source exposure: binary-analysis
// Static8b3f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b3f0;
extern void construct(Static8b3f0*, const Descriptor*);
extern void destroy(Static8b3f0*);
struct Static8b3f0 {
    void* value;
    Static8b3f0() { construct(this, &descriptor); }
    ~Static8b3f0() { destroy(this); }
};
