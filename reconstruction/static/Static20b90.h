// Source exposure: binary-analysis
// Static20b90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20b90;
extern void construct(Static20b90*, const Descriptor*);
extern void destroy(Static20b90*);
struct Static20b90 {
    void* value;
    Static20b90() { construct(this, &descriptor); }
    ~Static20b90() { destroy(this); }
};
