// Source exposure: binary-analysis
// Static100ea0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static100ea0;
extern void construct(Static100ea0*, const Descriptor*);
extern void destroy(Static100ea0*);
struct Static100ea0 {
    void* value;
    Static100ea0() { construct(this, &descriptor); }
    ~Static100ea0() { destroy(this); }
};
