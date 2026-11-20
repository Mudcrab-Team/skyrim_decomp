// Source exposure: binary-analysis; no external implementation source reused.
// Static1797940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1797940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1797940*);
    virtual void release(Static1797940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1797940*);
struct Static1797940 {
    void* value;
    Static1797940();
    ~Static1797940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
