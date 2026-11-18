// Source exposure: binary-analysis
// Static15c10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15c10;
extern void construct(Static15c10*, const Descriptor*);
extern void destroy(Static15c10*);
struct Static15c10 {
    void* value;
    Static15c10() { construct(this, &descriptor); }
    ~Static15c10() { destroy(this); }
};
