// Source exposure: binary-analysis; no external implementation source reused.
// Static1781bd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781bd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781bd0*);
    virtual void release(Static1781bd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781bd0*);
struct Static1781bd0 {
    void* value;
    Static1781bd0();
    ~Static1781bd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
