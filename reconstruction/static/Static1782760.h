// Source exposure: binary-analysis; no external implementation source reused.
// Static1782760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782760*);
    virtual void release(Static1782760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782760*);
struct Static1782760 {
    void* value;
    Static1782760();
    ~Static1782760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
