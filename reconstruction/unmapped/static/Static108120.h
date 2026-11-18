// Source exposure: binary-analysis
// Static108120, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108120;
extern void construct(Static108120*, const Descriptor*);
extern void destroy(Static108120*);
struct Static108120 {
    void* value;
    Static108120() { construct(this, &descriptor); }
    ~Static108120() { destroy(this); }
};
