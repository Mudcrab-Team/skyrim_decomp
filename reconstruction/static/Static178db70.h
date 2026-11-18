// Source exposure: binary-analysis; no external implementation source reused.
// Static178db70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178db70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178db70*);
    virtual void release(Static178db70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178db70*);
struct Static178db70 {
    void* value;
    Static178db70();
    ~Static178db70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
