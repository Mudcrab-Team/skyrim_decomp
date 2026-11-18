// Source exposure: binary-analysis; no external implementation source reused.
// Static1755940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755940*);
    virtual void release(Static1755940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755940*);
struct Static1755940 {
    void* value;
    Static1755940();
    ~Static1755940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
