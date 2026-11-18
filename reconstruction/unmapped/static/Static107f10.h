// Source exposure: binary-analysis
// Static107f10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static107f10;
extern void construct(Static107f10*, const Descriptor*);
extern void destroy(Static107f10*);
struct Static107f10 {
    void* value;
    Static107f10() { construct(this, &descriptor); }
    ~Static107f10() { destroy(this); }
};
