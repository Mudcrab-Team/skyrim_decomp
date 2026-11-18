// Source exposure: binary-analysis; no external implementation source reused.
// Static1779110, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779110;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779110*);
    virtual void release(Static1779110*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779110*);
struct Static1779110 {
    void* value;
    Static1779110();
    ~Static1779110() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
