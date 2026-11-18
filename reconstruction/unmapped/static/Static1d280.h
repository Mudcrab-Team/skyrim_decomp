// Source exposure: binary-analysis
// Static1d280, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d280;
extern void construct(Static1d280*, const Descriptor*);
extern void destroy(Static1d280*);
struct Static1d280 {
    void* value;
    Static1d280() { construct(this, &descriptor); }
    ~Static1d280() { destroy(this); }
};
