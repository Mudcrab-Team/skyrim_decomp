// Source exposure: binary-analysis; no external implementation source reused.
// Static1756520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756520*);
    virtual void release(Static1756520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756520*);
struct Static1756520 {
    void* value;
    Static1756520();
    ~Static1756520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
