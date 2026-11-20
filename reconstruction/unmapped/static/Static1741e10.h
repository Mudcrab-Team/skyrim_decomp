// Source exposure: binary-analysis; no external implementation source reused.
// Static1741e10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741e10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741e10*);
    virtual void release(Static1741e10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741e10*);
struct Static1741e10 {
    void* value;
    Static1741e10();
    ~Static1741e10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
