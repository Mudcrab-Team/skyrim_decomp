// Source exposure: binary-analysis
// Static1de60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1de60;
extern void construct(Static1de60*, const Descriptor*);
extern void destroy(Static1de60*);
struct Static1de60 {
    void* value;
    Static1de60() { construct(this, &descriptor); }
    ~Static1de60() { destroy(this); }
};
