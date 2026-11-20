// Source exposure: binary-analysis; no external implementation source reused.
// Static1795650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795650*);
    virtual void release(Static1795650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795650*);
struct Static1795650 {
    void* value;
    Static1795650();
    ~Static1795650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
