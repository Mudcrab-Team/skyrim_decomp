// Source exposure: binary-analysis; no external implementation source reused.
// Static179f530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f530*);
    virtual void release(Static179f530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f530*);
struct Static179f530 {
    void* value;
    Static179f530();
    ~Static179f530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
