// Source exposure: binary-analysis; no external implementation source reused.
// Static178bf20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178bf20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178bf20*);
    virtual void release(Static178bf20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178bf20*);
struct Static178bf20 {
    void* value;
    Static178bf20();
    ~Static178bf20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
