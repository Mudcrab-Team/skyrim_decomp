// Source exposure: binary-analysis
// Static23cc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23cc0;
extern void construct(Static23cc0*, const Descriptor*);
extern void destroy(Static23cc0*);
struct Static23cc0 {
    void* value;
    Static23cc0() { construct(this, &descriptor); }
    ~Static23cc0() { destroy(this); }
};
