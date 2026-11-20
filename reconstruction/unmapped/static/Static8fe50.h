// Source exposure: binary-analysis
// Static8fe50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fe50;
extern void construct(Static8fe50*, const Descriptor*);
extern void destroy(Static8fe50*);
struct Static8fe50 {
    void* value;
    Static8fe50() { construct(this, &descriptor); }
    ~Static8fe50() { destroy(this); }
};
