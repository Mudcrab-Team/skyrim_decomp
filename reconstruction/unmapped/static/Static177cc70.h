// Source exposure: binary-analysis; no external implementation source reused.
// Static177cc70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177cc70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177cc70*);
    virtual void release(Static177cc70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177cc70*);
struct Static177cc70 {
    void* value;
    Static177cc70();
    ~Static177cc70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
