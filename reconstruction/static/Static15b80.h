// Source exposure: binary-analysis
// Static15b80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15b80;
extern void construct(Static15b80*, const Descriptor*);
extern void destroy(Static15b80*);
struct Static15b80 {
    void* value;
    Static15b80() { construct(this, &descriptor); }
    ~Static15b80() { destroy(this); }
};
