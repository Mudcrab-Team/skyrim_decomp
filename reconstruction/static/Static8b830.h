// Source exposure: binary-analysis
// Static8b830, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b830;
extern void construct(Static8b830*, const Descriptor*);
extern void destroy(Static8b830*);
struct Static8b830 {
    void* value;
    Static8b830() { construct(this, &descriptor); }
    ~Static8b830() { destroy(this); }
};
