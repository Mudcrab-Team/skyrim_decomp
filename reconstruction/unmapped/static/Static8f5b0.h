// Source exposure: binary-analysis
// Static8f5b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f5b0;
extern void construct(Static8f5b0*, const Descriptor*);
extern void destroy(Static8f5b0*);
struct Static8f5b0 {
    void* value;
    Static8f5b0() { construct(this, &descriptor); }
    ~Static8f5b0() { destroy(this); }
};
