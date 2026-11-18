// Source exposure: binary-analysis; no external implementation source reused.
// Static1759040, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759040;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759040*);
    virtual void release(Static1759040*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759040*);
struct Static1759040 {
    void* value;
    Static1759040();
    ~Static1759040() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
