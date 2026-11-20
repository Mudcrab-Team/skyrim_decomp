// Source exposure: binary-analysis
// Static1dd10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1dd10;
extern void construct(Static1dd10*, const Descriptor*);
extern void destroy(Static1dd10*);
struct Static1dd10 {
    void* value;
    Static1dd10() { construct(this, &descriptor); }
    ~Static1dd10() { destroy(this); }
};
