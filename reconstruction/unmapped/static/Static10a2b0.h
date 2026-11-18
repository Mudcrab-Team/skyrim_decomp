// Source exposure: binary-analysis
// Static10a2b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10a2b0;
extern void construct(Static10a2b0*, const Descriptor*);
extern void destroy(Static10a2b0*);
struct Static10a2b0 {
    void* value;
    Static10a2b0() { construct(this, &descriptor); }
    ~Static10a2b0() { destroy(this); }
};
