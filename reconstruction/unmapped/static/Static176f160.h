// Source exposure: binary-analysis; no external implementation source reused.
// Static176f160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f160*);
    virtual void release(Static176f160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f160*);
struct Static176f160 {
    void* value;
    Static176f160();
    ~Static176f160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
