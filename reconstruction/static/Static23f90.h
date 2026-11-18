// Source exposure: binary-analysis
// Static23f90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23f90;
extern void construct(Static23f90*, const Descriptor*);
extern void destroy(Static23f90*);
struct Static23f90 {
    void* value;
    Static23f90() { construct(this, &descriptor); }
    ~Static23f90() { destroy(this); }
};
