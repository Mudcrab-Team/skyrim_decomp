// Source exposure: binary-analysis; no external implementation source reused.
// Static178c600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c600*);
    virtual void release(Static178c600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c600*);
struct Static178c600 {
    void* value;
    Static178c600();
    ~Static178c600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
