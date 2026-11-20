// Source exposure: binary-analysis; no external implementation source reused.
// Static173cf70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cf70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cf70*);
    virtual void release(Static173cf70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cf70*);
struct Static173cf70 {
    void* value;
    Static173cf70();
    ~Static173cf70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
