// Source exposure: binary-analysis; no external implementation source reused.
// Static176e670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e670*);
    virtual void release(Static176e670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e670*);
struct Static176e670 {
    void* value;
    Static176e670();
    ~Static176e670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
