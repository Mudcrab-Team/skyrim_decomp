// Source exposure: binary-analysis
// Static8f670, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f670;
extern void construct(Static8f670*, const Descriptor*);
extern void destroy(Static8f670*);
struct Static8f670 {
    void* value;
    Static8f670() { construct(this, &descriptor); }
    ~Static8f670() { destroy(this); }
};
