// Source exposure: binary-analysis
// Static8bdd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8bdd0;
extern void construct(Static8bdd0*, const Descriptor*);
extern void destroy(Static8bdd0*);
struct Static8bdd0 {
    void* value;
    Static8bdd0() { construct(this, &descriptor); }
    ~Static8bdd0() { destroy(this); }
};
