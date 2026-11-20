// Source exposure: binary-analysis; no external implementation source reused.
// Static174da30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174da30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174da30*);
    virtual void release(Static174da30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174da30*);
struct Static174da30 {
    void* value;
    Static174da30();
    ~Static174da30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
