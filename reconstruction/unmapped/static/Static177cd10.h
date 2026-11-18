// Source exposure: binary-analysis; no external implementation source reused.
// Static177cd10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177cd10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177cd10*);
    virtual void release(Static177cd10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177cd10*);
struct Static177cd10 {
    void* value;
    Static177cd10();
    ~Static177cd10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
