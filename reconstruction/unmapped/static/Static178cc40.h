// Source exposure: binary-analysis; no external implementation source reused.
// Static178cc40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178cc40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178cc40*);
    virtual void release(Static178cc40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178cc40*);
struct Static178cc40 {
    void* value;
    Static178cc40();
    ~Static178cc40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
