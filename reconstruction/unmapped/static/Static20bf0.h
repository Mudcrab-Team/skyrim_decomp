// Source exposure: binary-analysis
// Static20bf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20bf0;
extern void construct(Static20bf0*, const Descriptor*);
extern void destroy(Static20bf0*);
struct Static20bf0 {
    void* value;
    Static20bf0() { construct(this, &descriptor); }
    ~Static20bf0() { destroy(this); }
};
