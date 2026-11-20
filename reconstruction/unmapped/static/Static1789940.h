// Source exposure: binary-analysis; no external implementation source reused.
// Static1789940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789940*);
    virtual void release(Static1789940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789940*);
struct Static1789940 {
    void* value;
    Static1789940();
    ~Static1789940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
