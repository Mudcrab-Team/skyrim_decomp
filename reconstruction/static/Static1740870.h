// Source exposure: binary-analysis; no external implementation source reused.
// Static1740870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740870*);
    virtual void release(Static1740870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740870*);
struct Static1740870 {
    void* value;
    Static1740870();
    ~Static1740870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
