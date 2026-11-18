// Source exposure: binary-analysis; no external implementation source reused.
// Static176b240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b240*);
    virtual void release(Static176b240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b240*);
struct Static176b240 {
    void* value;
    Static176b240();
    ~Static176b240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
