// Source exposure: binary-analysis; no external implementation source reused.
// Static1760520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760520*);
    virtual void release(Static1760520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760520*);
struct Static1760520 {
    void* value;
    Static1760520();
    ~Static1760520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
