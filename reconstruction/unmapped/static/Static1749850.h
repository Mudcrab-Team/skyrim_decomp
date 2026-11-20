// Source exposure: binary-analysis; no external implementation source reused.
// Static1749850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1749850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1749850*);
    virtual void release(Static1749850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1749850*);
struct Static1749850 {
    void* value;
    Static1749850();
    ~Static1749850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
