// Source exposure: binary-analysis; no external implementation source reused.
// Static178ab80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ab80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ab80*);
    virtual void release(Static178ab80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ab80*);
struct Static178ab80 {
    void* value;
    Static178ab80();
    ~Static178ab80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
