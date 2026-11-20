// Source exposure: binary-analysis; no external implementation source reused.
// Static1767b90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767b90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767b90*);
    virtual void release(Static1767b90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767b90*);
struct Static1767b90 {
    void* value;
    Static1767b90();
    ~Static1767b90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
