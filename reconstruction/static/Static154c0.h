// Source exposure: binary-analysis
// Static154c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static154c0;
extern void construct(Static154c0*, const Descriptor*);
extern void destroy(Static154c0*);
struct Static154c0 {
    void* value;
    Static154c0() { construct(this, &descriptor); }
    ~Static154c0() { destroy(this); }
};
