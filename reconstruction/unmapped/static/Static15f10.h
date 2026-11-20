// Source exposure: binary-analysis
// Static15f10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15f10;
extern void construct(Static15f10*, const Descriptor*);
extern void destroy(Static15f10*);
struct Static15f10 {
    void* value;
    Static15f10() { construct(this, &descriptor); }
    ~Static15f10() { destroy(this); }
};
