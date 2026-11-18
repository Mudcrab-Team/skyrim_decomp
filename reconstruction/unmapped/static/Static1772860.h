// Source exposure: binary-analysis; no external implementation source reused.
// Static1772860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772860*);
    virtual void release(Static1772860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772860*);
struct Static1772860 {
    void* value;
    Static1772860();
    ~Static1772860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
