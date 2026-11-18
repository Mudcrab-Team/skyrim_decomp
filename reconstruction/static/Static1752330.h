// Source exposure: binary-analysis; no external implementation source reused.
// Static1752330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752330*);
    virtual void release(Static1752330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752330*);
struct Static1752330 {
    void* value;
    Static1752330();
    ~Static1752330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
