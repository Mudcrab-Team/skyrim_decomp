// Source exposure: binary-analysis
// Static15040, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15040;
extern void construct(Static15040*, const Descriptor*);
extern void destroy(Static15040*);
struct Static15040 {
    void* value;
    Static15040() { construct(this, &descriptor); }
    ~Static15040() { destroy(this); }
};
