// Source exposure: binary-analysis; no external implementation source reused.
// Static1770c40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770c40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770c40*);
    virtual void release(Static1770c40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770c40*);
struct Static1770c40 {
    void* value;
    Static1770c40();
    ~Static1770c40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
