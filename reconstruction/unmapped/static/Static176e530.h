// Source exposure: binary-analysis; no external implementation source reused.
// Static176e530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e530*);
    virtual void release(Static176e530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e530*);
struct Static176e530 {
    void* value;
    Static176e530();
    ~Static176e530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
