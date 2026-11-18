// Source exposure: binary-analysis; no external implementation source reused.
// Static178ae00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ae00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ae00*);
    virtual void release(Static178ae00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ae00*);
struct Static178ae00 {
    void* value;
    Static178ae00();
    ~Static178ae00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
