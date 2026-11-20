// Source exposure: binary-analysis
// Static15e50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15e50;
extern void construct(Static15e50*, const Descriptor*);
extern void destroy(Static15e50*);
struct Static15e50 {
    void* value;
    Static15e50() { construct(this, &descriptor); }
    ~Static15e50() { destroy(this); }
};
