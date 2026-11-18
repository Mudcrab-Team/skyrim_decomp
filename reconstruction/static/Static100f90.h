// Source exposure: binary-analysis
// Static100f90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static100f90;
extern void construct(Static100f90*, const Descriptor*);
extern void destroy(Static100f90*);
struct Static100f90 {
    void* value;
    Static100f90() { construct(this, &descriptor); }
    ~Static100f90() { destroy(this); }
};
