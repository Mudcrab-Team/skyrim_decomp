// Source exposure: binary-analysis; no external implementation source reused.
// Static1795e00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795e00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795e00*);
    virtual void release(Static1795e00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795e00*);
struct Static1795e00 {
    void* value;
    Static1795e00();
    ~Static1795e00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
