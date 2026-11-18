// Source exposure: binary-analysis; no external implementation source reused.
// Static1795510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795510*);
    virtual void release(Static1795510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795510*);
struct Static1795510 {
    void* value;
    Static1795510();
    ~Static1795510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
