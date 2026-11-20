// Source exposure: binary-analysis; no external implementation source reused.
// Static178a680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a680*);
    virtual void release(Static178a680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a680*);
struct Static178a680 {
    void* value;
    Static178a680();
    ~Static178a680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
