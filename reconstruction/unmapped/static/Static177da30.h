// Source exposure: binary-analysis; no external implementation source reused.
// Static177da30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177da30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177da30*);
    virtual void release(Static177da30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177da30*);
struct Static177da30 {
    void* value;
    Static177da30();
    ~Static177da30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
