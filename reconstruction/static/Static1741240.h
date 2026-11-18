// Source exposure: binary-analysis; no external implementation source reused.
// Static1741240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741240*);
    virtual void release(Static1741240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741240*);
struct Static1741240 {
    void* value;
    Static1741240();
    ~Static1741240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
