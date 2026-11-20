// Source exposure: binary-analysis; no external implementation source reused.
// Static1770560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770560*);
    virtual void release(Static1770560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770560*);
struct Static1770560 {
    void* value;
    Static1770560();
    ~Static1770560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
