// Source exposure: binary-analysis; no external implementation source reused.
// Static1773b70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773b70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773b70*);
    virtual void release(Static1773b70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773b70*);
struct Static1773b70 {
    void* value;
    Static1773b70();
    ~Static1773b70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
