// Source exposure: binary-analysis; no external implementation source reused.
// Static178eb20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178eb20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178eb20*);
    virtual void release(Static178eb20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178eb20*);
struct Static178eb20 {
    void* value;
    Static178eb20();
    ~Static178eb20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
