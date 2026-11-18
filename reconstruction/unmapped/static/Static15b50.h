// Source exposure: binary-analysis
// Static15b50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15b50;
extern void construct(Static15b50*, const Descriptor*);
extern void destroy(Static15b50*);
struct Static15b50 {
    void* value;
    Static15b50() { construct(this, &descriptor); }
    ~Static15b50() { destroy(this); }
};
