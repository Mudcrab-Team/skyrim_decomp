// Source exposure: binary-analysis; no external implementation source reused.
// Static176d900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d900*);
    virtual void release(Static176d900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d900*);
struct Static176d900 {
    void* value;
    Static176d900();
    ~Static176d900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
