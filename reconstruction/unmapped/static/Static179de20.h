// Source exposure: binary-analysis; no external implementation source reused.
// Static179de20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179de20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179de20*);
    virtual void release(Static179de20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179de20*);
struct Static179de20 {
    void* value;
    Static179de20();
    ~Static179de20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
