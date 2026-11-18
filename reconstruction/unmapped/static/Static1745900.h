// Source exposure: binary-analysis; no external implementation source reused.
// Static1745900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1745900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1745900*);
    virtual void release(Static1745900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1745900*);
struct Static1745900 {
    void* value;
    Static1745900();
    ~Static1745900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
