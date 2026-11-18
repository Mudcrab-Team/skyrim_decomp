// Source exposure: binary-analysis; no external implementation source reused.
// Static177ad80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ad80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ad80*);
    virtual void release(Static177ad80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ad80*);
struct Static177ad80 {
    void* value;
    Static177ad80();
    ~Static177ad80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
