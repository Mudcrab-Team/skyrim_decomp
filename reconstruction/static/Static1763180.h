// Source exposure: binary-analysis; no external implementation source reused.
// Static1763180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763180*);
    virtual void release(Static1763180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763180*);
struct Static1763180 {
    void* value;
    Static1763180();
    ~Static1763180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
