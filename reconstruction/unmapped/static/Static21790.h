// Source exposure: binary-analysis
// Static21790, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21790;
extern void construct(Static21790*, const Descriptor*);
extern void destroy(Static21790*);
struct Static21790 {
    void* value;
    Static21790() { construct(this, &descriptor); }
    ~Static21790() { destroy(this); }
};
