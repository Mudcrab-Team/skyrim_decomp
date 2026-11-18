// Source exposure: binary-analysis; no external implementation source reused.
// Static178d830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d830*);
    virtual void release(Static178d830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d830*);
struct Static178d830 {
    void* value;
    Static178d830();
    ~Static178d830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
