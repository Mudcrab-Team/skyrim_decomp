// Source exposure: binary-analysis; no external implementation source reused.
// Static173cf10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cf10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cf10*);
    virtual void release(Static173cf10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cf10*);
struct Static173cf10 {
    void* value;
    Static173cf10();
    ~Static173cf10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
