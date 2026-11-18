// Source exposure: binary-analysis; no external implementation source reused.
// Static178c650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c650*);
    virtual void release(Static178c650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c650*);
struct Static178c650 {
    void* value;
    Static178c650();
    ~Static178c650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
