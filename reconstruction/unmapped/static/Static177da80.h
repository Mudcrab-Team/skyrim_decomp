// Source exposure: binary-analysis; no external implementation source reused.
// Static177da80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177da80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177da80*);
    virtual void release(Static177da80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177da80*);
struct Static177da80 {
    void* value;
    Static177da80();
    ~Static177da80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
