// Source exposure: binary-analysis
// Static100e70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static100e70;
extern void construct(Static100e70*, const Descriptor*);
extern void destroy(Static100e70*);
struct Static100e70 {
    void* value;
    Static100e70() { construct(this, &descriptor); }
    ~Static100e70() { destroy(this); }
};
