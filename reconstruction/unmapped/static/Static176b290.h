// Source exposure: binary-analysis; no external implementation source reused.
// Static176b290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b290*);
    virtual void release(Static176b290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b290*);
struct Static176b290 {
    void* value;
    Static176b290();
    ~Static176b290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
