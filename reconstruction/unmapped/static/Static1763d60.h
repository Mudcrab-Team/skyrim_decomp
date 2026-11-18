// Source exposure: binary-analysis; no external implementation source reused.
// Static1763d60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763d60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763d60*);
    virtual void release(Static1763d60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763d60*);
struct Static1763d60 {
    void* value;
    Static1763d60();
    ~Static1763d60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
