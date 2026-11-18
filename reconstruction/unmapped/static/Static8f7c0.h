// Source exposure: binary-analysis
// Static8f7c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f7c0;
extern void construct(Static8f7c0*, const Descriptor*);
extern void destroy(Static8f7c0*);
struct Static8f7c0 {
    void* value;
    Static8f7c0() { construct(this, &descriptor); }
    ~Static8f7c0() { destroy(this); }
};
