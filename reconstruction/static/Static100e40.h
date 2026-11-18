// Source exposure: binary-analysis
// Static100e40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static100e40;
extern void construct(Static100e40*, const Descriptor*);
extern void destroy(Static100e40*);
struct Static100e40 {
    void* value;
    Static100e40() { construct(this, &descriptor); }
    ~Static100e40() { destroy(this); }
};
