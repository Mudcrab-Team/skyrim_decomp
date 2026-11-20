// Source exposure: binary-analysis
// Static107f40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static107f40;
extern void construct(Static107f40*, const Descriptor*);
extern void destroy(Static107f40*);
struct Static107f40 {
    void* value;
    Static107f40() { construct(this, &descriptor); }
    ~Static107f40() { destroy(this); }
};
