// Source exposure: binary-analysis; no external implementation source reused.
// Static1756d40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756d40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756d40*);
    virtual void release(Static1756d40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756d40*);
struct Static1756d40 {
    void* value;
    Static1756d40();
    ~Static1756d40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
