// Source exposure: binary-analysis; no external implementation source reused.
// Static176b920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b920*);
    virtual void release(Static176b920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b920*);
struct Static176b920 {
    void* value;
    Static176b920();
    ~Static176b920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
