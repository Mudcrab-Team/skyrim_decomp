// Source exposure: binary-analysis; no external implementation source reused.
// Static179a880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179a880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179a880*);
    virtual void release(Static179a880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179a880*);
struct Static179a880 {
    void* value;
    Static179a880();
    ~Static179a880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
