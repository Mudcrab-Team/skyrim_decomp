// Source exposure: binary-analysis
// Static100de0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static100de0;
extern void construct(Static100de0*, const Descriptor*);
extern void destroy(Static100de0*);
struct Static100de0 {
    void* value;
    Static100de0() { construct(this, &descriptor); }
    ~Static100de0() { destroy(this); }
};
