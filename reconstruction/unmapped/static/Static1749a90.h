// Source exposure: binary-analysis; no external implementation source reused.
// Static1749a90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1749a90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1749a90*);
    virtual void release(Static1749a90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1749a90*);
struct Static1749a90 {
    void* value;
    Static1749a90();
    ~Static1749a90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
