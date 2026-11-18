// Source exposure: binary-analysis; no external implementation source reused.
// Static177fe70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fe70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fe70*);
    virtual void release(Static177fe70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fe70*);
struct Static177fe70 {
    void* value;
    Static177fe70();
    ~Static177fe70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
