// Source exposure: binary-analysis
// Static8fee0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fee0;
extern void construct(Static8fee0*, const Descriptor*);
extern void destroy(Static8fee0*);
struct Static8fee0 {
    void* value;
    Static8fee0() { construct(this, &descriptor); }
    ~Static8fee0() { destroy(this); }
};
