// Source exposure: binary-analysis
// Static107f70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static107f70;
extern void construct(Static107f70*, const Descriptor*);
extern void destroy(Static107f70*);
struct Static107f70 {
    void* value;
    Static107f70() { construct(this, &descriptor); }
    ~Static107f70() { destroy(this); }
};
