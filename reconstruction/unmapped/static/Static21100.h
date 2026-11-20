// Source exposure: binary-analysis
// Static21100, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21100;
extern void construct(Static21100*, const Descriptor*);
extern void destroy(Static21100*);
struct Static21100 {
    void* value;
    Static21100() { construct(this, &descriptor); }
    ~Static21100() { destroy(this); }
};
