// Source exposure: binary-analysis; no external implementation source reused.
// Static1756d90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756d90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756d90*);
    virtual void release(Static1756d90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756d90*);
struct Static1756d90 {
    void* value;
    Static1756d90();
    ~Static1756d90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
