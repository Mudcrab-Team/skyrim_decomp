// Source exposure: binary-analysis; no external implementation source reused.
// Static178c790, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c790;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c790*);
    virtual void release(Static178c790*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c790*);
struct Static178c790 {
    void* value;
    Static178c790();
    ~Static178c790() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
