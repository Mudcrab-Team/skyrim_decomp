// Source exposure: binary-analysis; no external implementation source reused.
// Static173ec40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ec40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ec40*);
    virtual void release(Static173ec40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ec40*);
struct Static173ec40 {
    void* value;
    Static173ec40();
    ~Static173ec40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
