// Source exposure: binary-analysis; no external implementation source reused.
// Static1768630, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768630;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768630*);
    virtual void release(Static1768630*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768630*);
struct Static1768630 {
    void* value;
    Static1768630();
    ~Static1768630() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
