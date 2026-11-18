// Source exposure: binary-analysis
// Static1e280, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1e280;
extern void construct(Static1e280*, const Descriptor*);
extern void destroy(Static1e280*);
struct Static1e280 {
    void* value;
    Static1e280() { construct(this, &descriptor); }
    ~Static1e280() { destroy(this); }
};
