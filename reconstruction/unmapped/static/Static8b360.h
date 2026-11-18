// Source exposure: binary-analysis
// Static8b360, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b360;
extern void construct(Static8b360*, const Descriptor*);
extern void destroy(Static8b360*);
struct Static8b360 {
    void* value;
    Static8b360() { construct(this, &descriptor); }
    ~Static8b360() { destroy(this); }
};
