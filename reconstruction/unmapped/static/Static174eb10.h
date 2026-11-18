// Source exposure: binary-analysis; no external implementation source reused.
// Static174eb10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174eb10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174eb10*);
    virtual void release(Static174eb10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174eb10*);
struct Static174eb10 {
    void* value;
    Static174eb10();
    ~Static174eb10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
