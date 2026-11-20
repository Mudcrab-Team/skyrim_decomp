// Source exposure: binary-analysis; no external implementation source reused.
// Static1781180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781180*);
    virtual void release(Static1781180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781180*);
struct Static1781180 {
    void* value;
    Static1781180();
    ~Static1781180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
