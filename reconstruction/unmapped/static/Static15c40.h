// Source exposure: binary-analysis
// Static15c40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15c40;
extern void construct(Static15c40*, const Descriptor*);
extern void destroy(Static15c40*);
struct Static15c40 {
    void* value;
    Static15c40() { construct(this, &descriptor); }
    ~Static15c40() { destroy(this); }
};
