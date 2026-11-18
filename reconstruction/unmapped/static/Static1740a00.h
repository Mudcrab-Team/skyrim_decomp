// Source exposure: binary-analysis; no external implementation source reused.
// Static1740a00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740a00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740a00*);
    virtual void release(Static1740a00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740a00*);
struct Static1740a00 {
    void* value;
    Static1740a00();
    ~Static1740a00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
