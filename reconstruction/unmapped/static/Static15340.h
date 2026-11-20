// Source exposure: binary-analysis
// Static15340, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15340;
extern void construct(Static15340*, const Descriptor*);
extern void destroy(Static15340*);
struct Static15340 {
    void* value;
    Static15340() { construct(this, &descriptor); }
    ~Static15340() { destroy(this); }
};
