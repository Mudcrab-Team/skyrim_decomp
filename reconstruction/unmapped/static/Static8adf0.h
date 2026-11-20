// Source exposure: binary-analysis
// Static8adf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8adf0;
extern void construct(Static8adf0*, const Descriptor*);
extern void destroy(Static8adf0*);
struct Static8adf0 {
    void* value;
    Static8adf0() { construct(this, &descriptor); }
    ~Static8adf0() { destroy(this); }
};
