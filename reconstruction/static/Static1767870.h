// Source exposure: binary-analysis; no external implementation source reused.
// Static1767870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767870*);
    virtual void release(Static1767870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767870*);
struct Static1767870 {
    void* value;
    Static1767870();
    ~Static1767870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
