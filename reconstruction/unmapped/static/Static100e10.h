// Source exposure: binary-analysis
// Static100e10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static100e10;
extern void construct(Static100e10*, const Descriptor*);
extern void destroy(Static100e10*);
struct Static100e10 {
    void* value;
    Static100e10() { construct(this, &descriptor); }
    ~Static100e10() { destroy(this); }
};
