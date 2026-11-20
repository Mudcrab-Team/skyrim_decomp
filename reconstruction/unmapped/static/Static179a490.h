// Source exposure: binary-analysis; no external implementation source reused.
// Static179a490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179a490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179a490*);
    virtual void release(Static179a490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179a490*);
struct Static179a490 {
    void* value;
    Static179a490();
    ~Static179a490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
