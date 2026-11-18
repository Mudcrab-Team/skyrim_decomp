// Source exposure: binary-analysis
// Static8fe20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fe20;
extern void construct(Static8fe20*, const Descriptor*);
extern void destroy(Static8fe20*);
struct Static8fe20 {
    void* value;
    Static8fe20() { construct(this, &descriptor); }
    ~Static8fe20() { destroy(this); }
};
