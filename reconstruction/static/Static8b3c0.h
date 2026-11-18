// Source exposure: binary-analysis
// Static8b3c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b3c0;
extern void construct(Static8b3c0*, const Descriptor*);
extern void destroy(Static8b3c0*);
struct Static8b3c0 {
    void* value;
    Static8b3c0() { construct(this, &descriptor); }
    ~Static8b3c0() { destroy(this); }
};
