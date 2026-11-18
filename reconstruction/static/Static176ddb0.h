// Source exposure: binary-analysis; no external implementation source reused.
// Static176ddb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ddb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ddb0*);
    virtual void release(Static176ddb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ddb0*);
struct Static176ddb0 {
    void* value;
    Static176ddb0();
    ~Static176ddb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
