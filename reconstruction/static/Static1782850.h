// Source exposure: binary-analysis; no external implementation source reused.
// Static1782850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782850*);
    virtual void release(Static1782850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782850*);
struct Static1782850 {
    void* value;
    Static1782850();
    ~Static1782850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
