// Source exposure: binary-analysis; no external implementation source reused.
// Static1785e10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785e10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785e10*);
    virtual void release(Static1785e10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785e10*);
struct Static1785e10 {
    void* value;
    Static1785e10();
    ~Static1785e10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
