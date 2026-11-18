// Source exposure: binary-analysis; no external implementation source reused.
// Static176f250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f250*);
    virtual void release(Static176f250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f250*);
struct Static176f250 {
    void* value;
    Static176f250();
    ~Static176f250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
