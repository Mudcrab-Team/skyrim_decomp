// Source exposure: binary-analysis; no external implementation source reused.
// Static176e030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e030*);
    virtual void release(Static176e030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e030*);
struct Static176e030 {
    void* value;
    Static176e030();
    ~Static176e030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
