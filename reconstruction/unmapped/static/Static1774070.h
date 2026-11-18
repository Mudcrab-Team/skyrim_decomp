// Source exposure: binary-analysis; no external implementation source reused.
// Static1774070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774070*);
    virtual void release(Static1774070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774070*);
struct Static1774070 {
    void* value;
    Static1774070();
    ~Static1774070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
