// Source exposure: binary-analysis
// Static9f760, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f760;
extern void construct(Static9f760*, const Descriptor*);
extern void destroy(Static9f760*);
struct Static9f760 {
    void* value;
    Static9f760() { construct(this, &descriptor); }
    ~Static9f760() { destroy(this); }
};
