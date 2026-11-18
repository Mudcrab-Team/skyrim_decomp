// Source exposure: binary-analysis
// Static8b7b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b7b0;
extern void construct(Static8b7b0*, const Descriptor*);
extern void destroy(Static8b7b0*);
struct Static8b7b0 {
    void* value;
    Static8b7b0() { construct(this, &descriptor); }
    ~Static8b7b0() { destroy(this); }
};
