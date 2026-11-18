// Source exposure: binary-analysis; no external implementation source reused.
// Static177d850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d850*);
    virtual void release(Static177d850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d850*);
struct Static177d850 {
    void* value;
    Static177d850();
    ~Static177d850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
