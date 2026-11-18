// Source exposure: binary-analysis
// Static23e10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23e10;
extern void construct(Static23e10*, const Descriptor*);
extern void destroy(Static23e10*);
struct Static23e10 {
    void* value;
    Static23e10() { construct(this, &descriptor); }
    ~Static23e10() { destroy(this); }
};
