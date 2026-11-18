// Source exposure: binary-analysis
// Static8b330, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b330;
extern void construct(Static8b330*, const Descriptor*);
extern void destroy(Static8b330*);
struct Static8b330 {
    void* value;
    Static8b330() { construct(this, &descriptor); }
    ~Static8b330() { destroy(this); }
};
