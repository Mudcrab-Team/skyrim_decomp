// Source exposure: binary-analysis; no external implementation source reused.
// Static173ed80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ed80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ed80*);
    virtual void release(Static173ed80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ed80*);
struct Static173ed80 {
    void* value;
    Static173ed80();
    ~Static173ed80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
