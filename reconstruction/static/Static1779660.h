// Source exposure: binary-analysis; no external implementation source reused.
// Static1779660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779660*);
    virtual void release(Static1779660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779660*);
struct Static1779660 {
    void* value;
    Static1779660();
    ~Static1779660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
