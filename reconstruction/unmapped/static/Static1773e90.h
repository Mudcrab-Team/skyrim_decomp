// Source exposure: binary-analysis; no external implementation source reused.
// Static1773e90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773e90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773e90*);
    virtual void release(Static1773e90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773e90*);
struct Static1773e90 {
    void* value;
    Static1773e90();
    ~Static1773e90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
