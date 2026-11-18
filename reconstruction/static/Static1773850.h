// Source exposure: binary-analysis; no external implementation source reused.
// Static1773850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773850*);
    virtual void release(Static1773850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773850*);
struct Static1773850 {
    void* value;
    Static1773850();
    ~Static1773850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
