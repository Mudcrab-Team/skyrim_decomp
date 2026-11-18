// Source exposure: binary-analysis
// Static15f40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15f40;
extern void construct(Static15f40*, const Descriptor*);
extern void destroy(Static15f40*);
struct Static15f40 {
    void* value;
    Static15f40() { construct(this, &descriptor); }
    ~Static15f40() { destroy(this); }
};
