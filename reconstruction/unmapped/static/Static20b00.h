// Source exposure: binary-analysis
// Static20b00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static20b00;
extern void construct(Static20b00*, const Descriptor*);
extern void destroy(Static20b00*);
struct Static20b00 {
    void* value;
    Static20b00() { construct(this, &descriptor); }
    ~Static20b00() { destroy(this); }
};
