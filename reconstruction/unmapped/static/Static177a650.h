// Source exposure: binary-analysis; no external implementation source reused.
// Static177a650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a650*);
    virtual void release(Static177a650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a650*);
struct Static177a650 {
    void* value;
    Static177a650();
    ~Static177a650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
