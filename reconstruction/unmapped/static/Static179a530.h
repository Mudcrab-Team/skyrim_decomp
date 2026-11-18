// Source exposure: binary-analysis; no external implementation source reused.
// Static179a530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179a530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179a530*);
    virtual void release(Static179a530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179a530*);
struct Static179a530 {
    void* value;
    Static179a530();
    ~Static179a530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
