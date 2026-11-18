// Source exposure: binary-analysis
// Static8ae20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8ae20;
extern void construct(Static8ae20*, const Descriptor*);
extern void destroy(Static8ae20*);
struct Static8ae20 {
    void* value;
    Static8ae20() { construct(this, &descriptor); }
    ~Static8ae20() { destroy(this); }
};
