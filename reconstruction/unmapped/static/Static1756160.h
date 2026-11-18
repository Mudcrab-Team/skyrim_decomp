// Source exposure: binary-analysis; no external implementation source reused.
// Static1756160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756160*);
    virtual void release(Static1756160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756160*);
struct Static1756160 {
    void* value;
    Static1756160();
    ~Static1756160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
