// Source exposure: binary-analysis; no external implementation source reused.
// Static1741560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741560*);
    virtual void release(Static1741560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741560*);
struct Static1741560 {
    void* value;
    Static1741560();
    ~Static1741560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
