// Source exposure: binary-analysis
// Static8b4b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b4b0;
extern void construct(Static8b4b0*, const Descriptor*);
extern void destroy(Static8b4b0*);
struct Static8b4b0 {
    void* value;
    Static8b4b0() { construct(this, &descriptor); }
    ~Static8b4b0() { destroy(this); }
};
