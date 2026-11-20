// Source exposure: binary-analysis; no external implementation source reused.
// Static1796140, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796140;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796140*);
    virtual void release(Static1796140*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796140*);
struct Static1796140 {
    void* value;
    Static1796140();
    ~Static1796140() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
