// Source exposure: binary-analysis
// Static1de00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1de00;
extern void construct(Static1de00*, const Descriptor*);
extern void destroy(Static1de00*);
struct Static1de00 {
    void* value;
    Static1de00() { construct(this, &descriptor); }
    ~Static1de00() { destroy(this); }
};
