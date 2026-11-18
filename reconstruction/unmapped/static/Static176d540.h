// Source exposure: binary-analysis; no external implementation source reused.
// Static176d540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d540*);
    virtual void release(Static176d540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d540*);
struct Static176d540 {
    void* value;
    Static176d540();
    ~Static176d540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
