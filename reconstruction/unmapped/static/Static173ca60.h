// Source exposure: binary-analysis; no external implementation source reused.
// Static173ca60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ca60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ca60*);
    virtual void release(Static173ca60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ca60*);
struct Static173ca60 {
    void* value;
    Static173ca60();
    ~Static173ca60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
