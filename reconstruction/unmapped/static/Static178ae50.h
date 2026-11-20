// Source exposure: binary-analysis; no external implementation source reused.
// Static178ae50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ae50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ae50*);
    virtual void release(Static178ae50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ae50*);
struct Static178ae50 {
    void* value;
    Static178ae50();
    ~Static178ae50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
