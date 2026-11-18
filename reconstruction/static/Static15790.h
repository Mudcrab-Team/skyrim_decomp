// Source exposure: binary-analysis
// Static15790, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15790;
extern void construct(Static15790*, const Descriptor*);
extern void destroy(Static15790*);
struct Static15790 {
    void* value;
    Static15790() { construct(this, &descriptor); }
    ~Static15790() { destroy(this); }
};
