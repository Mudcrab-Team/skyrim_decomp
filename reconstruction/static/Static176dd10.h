// Source exposure: binary-analysis; no external implementation source reused.
// Static176dd10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176dd10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176dd10*);
    virtual void release(Static176dd10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176dd10*);
struct Static176dd10 {
    void* value;
    Static176dd10();
    ~Static176dd10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
