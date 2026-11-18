// Source exposure: binary-analysis
// Static10a160, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10a160;
extern void construct(Static10a160*, const Descriptor*);
extern void destroy(Static10a160*);
struct Static10a160 {
    void* value;
    Static10a160() { construct(this, &descriptor); }
    ~Static10a160() { destroy(this); }
};
