// Source exposure: binary-analysis
// Static108540, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108540;
extern void construct(Static108540*, const Descriptor*);
extern void destroy(Static108540*);
struct Static108540 {
    void* value;
    Static108540() { construct(this, &descriptor); }
    ~Static108540() { destroy(this); }
};
