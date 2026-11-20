// Source exposure: binary-analysis; no external implementation source reused.
// Static1793520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1793520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1793520*);
    virtual void release(Static1793520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1793520*);
struct Static1793520 {
    void* value;
    Static1793520();
    ~Static1793520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
